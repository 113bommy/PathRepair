#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
vector<long long> adj[1000000];
vector<bool> visited(1000000, 0);
vector<long long> color(1000000, 0);
long long n, k, x = 0;
void DFSUtil(long long u) {
  visited[u] = true;
  x++;
  for (long long i = 0; i < adj[u].size(); i++) {
    if (visited[adj[u][i]] == false) {
      DFSUtil(adj[u][i]);
    }
  }
}
long long M = 1e9 + 7;
long long DFS(long long n) {
  long long c = 0;
  for (long long u = 1; u <= n; u++) {
    if (visited[u] == false) {
      x = 0;
      DFSUtil(u);
      long long g = 1;
      for (long long i = 0; i < k; i++) {
        g *= x;
        g %= M;
      }
      c += g;
      c %= M;
    }
  }
  return c;
}
void aE(long long u, long long v) { adj[u].push_back(v); }
vector<long long> v(1000000, 0);
vector<long long> segTree(1000000, 0);
void build(long long low, long long high, long long pos) {
  if (low == high) {
    segTree[pos] = v[low];
    return;
  }
  long long mid = (low + high) / 2;
  build(low, mid, pos * 2);
  build(mid + 1, high, pos * 2 + 1);
  segTree[pos] = segTree[pos * 2] + segTree[pos * 2 + 1];
}
long long querry(long long low, long long high, long long l, long long r,
                 long long pos) {
  if (l <= low && r >= high)
    return segTree[pos];
  else if (r < low || l > high)
    return 0;
  long long mid = (low + high) / 2;
  return querry(low, mid, l, r, 2 * pos) +
         querry(mid + 1, high, l, r, 2 * pos + 1);
}
void update(long long low, long long high, long long index, long long val,
            long long pos) {
  if (low == high) {
    v[index] = val;
    segTree[pos] = val;
  } else {
    long long mid = (low + high) / 2;
    if (low <= index && index <= mid)
      update(low, mid, index, val, 2 * pos);
    else
      update(mid + 1, high, index, val, 2 * pos + 1);
    segTree[pos] = segTree[2 * pos] + segTree[2 * pos + 1];
  }
}
long long mes(string s1, string s2) {
  long long count = 0;
  for (long long i = 0; i < min(s1.size(), s2.size()); i++) {
    if (s1[i] != s2[i])
      break;
    else
      count++;
  }
  return count;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<pair<long long, long long> > point(n);
  for (long long i = 0; i < n; i++) cin >> point[i].first >> point[i].second;
  vector<pair<long double, long double> > nonvert;
  vector<long long> vert;
  map<long long, long long> vertm;
  map<pair<long double, long double>, long long> nonvertm;
  for (long long i = 0; i < n - 1; i++) {
    for (long long j = i + 1; j < n; j++) {
      long long x1, x2, y1, y2;
      x1 = point[i].first;
      x2 = point[j].first;
      y1 = point[i].second;
      y2 = point[j].second;
      if (x1 == x2) {
        if (vertm[x1] == 0) {
          vert.push_back(x1);
          vertm[x1] = 1;
        }
      } else {
        long double m, c;
        m = (long double)(y2 - y1) / (long double)(x2 - x1);
        c = (long double)(x2 * y1 - x1 * y2) / (long double)(x2 - x1);
        if (nonvertm[make_pair(m, c)] == 0) {
          nonvert.push_back(make_pair(m, c));
          nonvertm[make_pair(m, c)] = 1;
        }
      }
    }
  }
  sort((nonvert).begin(), (nonvert).end());
  vector<long long> same;
  long double last = nonvert[0].first;
  for (long long i = 0; i < nonvert.size(); i++) {
    long long count = 0, j = i;
    while (1) {
      if (nonvert[j].first == last) {
        count++;
        j++;
      } else {
        if (count > 1) same.push_back(count);
        count = 0;
        last = nonvert[j].first;
        i = j - 1;
        break;
      }
    }
  }
  long long u = vert.size() + nonvert.size();
  long long m = u * (u - 1) / 2;
  for (long long i = 0; i < same.size(); i++)
    m -= (same[i] * (same[i] - 1) / 2);
  if (vert.size() > 1) m -= (vert.size()) * (vert.size() - 1) / 2;
  cout << m << endl;
}
