#include <bits/stdc++.h>
using namespace std;
unsigned long long A, B, C;
const int BN = 2e5 + 500;
bitset<BN> adj[1200];
vector<int> edge[BN];
unsigned long long cal(
    unsigned long long n,
    vector<pair<unsigned long long, unsigned long long>> &con) {
  unsigned long long sum = 0;
  for (unsigned long long i = 0; i < n; i += 1) {
    sum += A * i * ((n - i - 1) * (n - i - 2) / 2);
    sum += B * i * (i * (n - i - 1));
    sum += C * i * (i * (i - 1) / 2);
  }
  int m = con.size();
  for (int i = 0; i < m; i += 1) {
    edge[con[i].first].push_back(con[i].second);
    edge[con[i].second].push_back(con[i].first);
  }
  vector<unsigned long long> edgesum[n];
  vector<int> id(n, -1);
  int ididx = 0;
  for (int i = 0; i < n; i += 1) {
    sort(edge[i].begin(), edge[i].end());
    edgesum[i].assign(edge[i].size() + 1, 0);
    for (int j = 1; j <= edge[i].size(); j += 1)
      edgesum[i][j] = edgesum[i][j - 1] + edge[i][j - 1];
    if (edge[i].size() >= 700) {
      id[i] = ididx++;
      for (int j : edge[i]) adj[id[i]][j] = 1;
    }
  }
  unsigned long long sub1 = 0;
  for (int i = 0; i < n; i += 1) {
    for (int j : edge[i]) {
      if (j > i) break;
      unsigned long long tj = j;
      unsigned long long cnt = tj * (tj - 1) / 2;
      sub1 += cnt * A + tj * (B * tj + C * i);
      cnt = i - j - 1;
      sub1 += cnt * (A * j + C * i) + B * ((cnt + 2 * j + 1) * cnt / 2);
    }
    unsigned long long psum = 0;
    int isize = edge[i].size();
    for (int j = 0; j < isize; j += 1) {
      if (edge[i][j] > i) break;
      unsigned long long tj = j;
      sub1 -= A * psum + tj * (B * edge[i][j] + C * i);
      psum += edge[i][j];
    }
  }
  sum -= sub1;
  unsigned long long sub2 = 0;
  unsigned long long psum = 0;
  unsigned long long pcnt = 0;
  for (int i = 0; i < n; i += 1) {
    sub2 += psum + pcnt * C * i;
    for (int j : edge[i]) {
      if (j > i) break;
      pcnt += 1;
      psum += A * j + B * i;
    }
  }
  for (int i = 0; i < n; i += 1) {
    for (int j : edge[i]) {
      if (j > i) break;
      int pos1 =
          lower_bound(edge[j].begin(), edge[j].end(), j) - edge[j].begin();
      sub2 -= A * (edgesum[j][pos1] - edgesum[j][0]) + pos1 * (B * j + C * i);
      int pos2 =
          lower_bound(edge[j].begin(), edge[j].end(), i) - edge[j].begin();
      sub2 -= B * (edgesum[j][pos2] - edgesum[j][pos1]) +
              (pos2 - pos1) * (A * j + C * i);
    }
  }
  for (int i = 0; i < n; i += 1) {
    if (id[i] == -1) {
      int isize = edge[i].size();
      for (int j = 0; j < isize; j += 1) {
        if (edge[i][j] > i) break;
        int v = edge[i][j];
        if (id[v] != -1) {
          for (int k = 0; k < j; k += 1) {
            if (adj[id[v]][edge[i][k]]) sub2 += A * edge[i][k] + B * v + C * i;
          }
        } else {
          vector<char> flag(n + 5, 0);
          for (int k : edge[v]) {
            if (k > v) break;
            flag[k] = 1;
          }
          for (int k = 0; k < j; k += 1) {
            if (flag[edge[i][k]]) sub2 += A * edge[i][k] + B * v + C * i;
          }
        }
      }
    } else {
      for (int j = 0; j < i; j += 1) {
        if (adj[id[i]][j] == 0) continue;
        for (int k : edge[j]) {
          if (k > j) break;
          if (adj[id[i]][k]) sub2 += A * k + B * j + C * i;
        }
      }
    }
  }
  sum -= sub2;
  return sum;
}
unsigned long long cal2(
    unsigned long long n,
    vector<pair<unsigned long long, unsigned long long>> &con) {
  int m = con.size();
  vector<unordered_set<int>> record(n);
  for (int i = 0; i < m; i += 1) {
    record[con[i].first].insert(con[i].second);
  }
  long long sum = 0;
  for (int i = 0; i < n; i += 1) {
    for (int j = i + 1; j < n; j += 1) {
      for (int k = j + 1; k < n; k += 1) {
        if (record[i].count(j) || record[i].count(k) || record[j].count(k))
          ;
        else
          sum += i * A + j * B + k * C;
      }
    }
  }
  cout << "ans: " << sum << endl;
}
int main() {
  unsigned long long n, m;
  cin >> n >> m;
  cin >> A >> B >> C;
  vector<pair<unsigned long long, unsigned long long>> con(m);
  for (int i = 0; i < m; i += 1) {
    scanf("%u %u", &con[i].first, &con[i].second);
    if (con[i].first > con[i].second) swap(con[i].first, con[i].second);
  }
  cout << cal(n, con) << endl;
}
