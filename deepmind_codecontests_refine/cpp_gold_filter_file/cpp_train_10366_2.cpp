#include <bits/stdc++.h>
using namespace std;
using itn = int;
const long double PI = 3.141592653589793238;
long long INF = 1000L * 1000L * 1000L + 150L;
long long pow(long long x, long long pw) {
  long long res = 1;
  for (; pw; pw >>= 1) {
    if (pw & 1) {
      res *= x;
    }
    x = x * x;
  }
  return res;
}
void NO() {
  cout << "NO";
  exit(0);
}
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long lcd(long long a, long long b) { return a * b / gcd(a, b); }
vector<long long> capitals;
vector<vector<long long>> G;
vector<bool> used(1003);
long long co = 0;
void dfs(long long v) {
  used[v] = true;
  co++;
  for (long long u : G[v]) {
    if (!used[u]) {
      dfs(u);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  long long n, m, k;
  cin >> n;
  long long LOG = 10;
  vector<vector<vector<long long>>> ANSWERS(
      n, vector<vector<long long>>(10, vector<long long>(2)));
  for (int i = 0; i < LOG; ++i) {
    for (int digit : {0, 1}) {
      vector<long long> query;
      for (int x = 0; x < n; ++x) {
        if (((x >> i) & 1) == (digit & 1)) {
          query.push_back(x);
        }
      }
      if (query.size() > 0) {
        cout << query.size() << "\n";
        for (long long t : query) {
          cout << t + 1 << " ";
        }
        cout << std::endl;
        for (int j = 0; j < n; ++j) {
          long long resp;
          cin >> resp;
          ANSWERS[j][i][digit] = resp;
        }
      } else {
        for (int j = 0; j < n; ++j) {
          ANSWERS[j][i][digit] = INF;
        }
      }
    }
  }
  cout << -1 << endl;
  for (int N = 0; N < n; ++N) {
    long long ans = INF;
    for (int i = 0; i < LOG; ++i) {
      int dig = (N >> i) & 1;
      ans = min(ans, ANSWERS[N][i][1 - dig]);
    }
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}
