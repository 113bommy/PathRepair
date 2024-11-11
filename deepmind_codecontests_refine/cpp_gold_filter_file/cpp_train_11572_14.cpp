#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res = (res * x);
    }
    n >>= 1;
    x = (x * x);
  }
  return res;
}
long long powerMOD(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res = (res * x) % 1000000007;
    }
    n >>= 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
int fact(int n) {
  int x = 1, i;
  for (i = n; i >= 2; i--) {
    x = x * i;
  }
  return x;
}
void factors(vector<pair<int, int>> &fac, int n) {
  int i;
  for (i = 1; i < sqrt(n); i++) {
    if (n % i == 0) {
      fac.push_back({i, n / i});
      if ((n / i) != i) {
        fac.push_back({n / i, i});
      }
    }
  }
}
void bipartite(vector<int> a[], int ind, int b[]) {
  int i, j;
  queue<int> c;
  c.push(ind);
  b[ind] = 1;
  while (!c.empty()) {
    j = c.front();
    c.pop();
    for (i = 0; i < a[j].size(); i++) {
      if (b[a[j][i]] == -1) {
        b[a[j][i]] = 1 - b[j];
        c.push(a[j][i]);
      }
    }
  }
  return;
}
int b[100000 + 2];
bool visited[100000 + 2];
void DFS(vector<int> a[], int ind) {
  int i, j = 0, k = -1;
  for (i = 0; i < a[ind].size(); i++) {
    if (!visited[a[ind][i]]) {
      j = 1;
      visited[a[ind][i]] = true;
      DFS(a, a[ind][i]);
    } else {
      k = a[ind][i];
    }
  }
  if (j == 1) {
    if (k == -1) {
      j = 0;
      for (i = 0; i < a[ind].size(); i++) {
        if (b[a[ind][i]] == 0) {
          j++;
        }
      }
      if ((j) % 2 == 0) {
        b[ind] = 1;
      }
    } else {
      j = 0;
      for (i = 0; i < a[ind].size(); i++) {
        if (b[a[ind][i]] == 0 && a[ind][i] != k) {
          j++;
        }
      }
      if ((j + 1) % 2 == 0) {
        b[ind] = 1;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  int i, j, k, n, l, x, t, m;
  cin >> n;
  vector<pair<char, int>> a(n), b(n);
  vector<pair<int, int>> ans;
  vector<int> c, d, cc, dd;
  for (i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (i = 0; i < n; i++) {
    cin >> b[i].first;
    b[i].second = i;
  }
  sort(a.begin(), a.end(), greater<pair<char, int>>());
  sort(b.begin(), b.end(), greater<pair<char, int>>());
  i = 0;
  j = 0;
  while ((j < n && i < n)) {
    if (a[i].first == '?' || b[j].first == '?') {
      break;
    }
    if (a[i].first == b[j].first) {
      ans.push_back({a[i].second, b[j].second});
      i++;
      j++;
    } else if (a[i].first > b[j].first) {
      c.push_back(a[i].second);
      i++;
    } else {
      d.push_back(b[j].second);
      j++;
    }
  }
  for (; i < n; i++) {
    if (a[i].first != '?') {
      c.push_back(a[i].second);
    } else {
      cc.push_back(a[i].second);
    }
  }
  for (; j < n; j++) {
    if (b[j].first != '?') {
      d.push_back(b[j].second);
    } else {
      dd.push_back(b[j].second);
    }
  }
  x = min(cc.size(), d.size());
  for (j = 0; j < x; j++) {
    ans.push_back({cc[j], d[j]});
  }
  l = min(dd.size(), c.size());
  for (j = 0; j < l; j++) {
    ans.push_back({c[j], dd[j]});
  }
  int y = min(cc.size(), dd.size());
  for (; j < y; j++) {
    ans.push_back({cc[x], dd[l]});
    x++;
    l++;
  }
  cout << ans.size() << "\n";
  for (i = 0; i < ans.size(); i++) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
  }
}
