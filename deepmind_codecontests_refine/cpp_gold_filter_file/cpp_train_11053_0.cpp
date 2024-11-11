#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n;
long long a[100000];
pair<long long, int> arr[100000];
long long gcd(long long num1, long long num2) {
  if (num1 > num2) swap(num1, num2);
  while (num1) {
    long long tmp = num2 % num1;
    num2 = num1;
    num1 = tmp;
  }
  return num2;
}
void bruteforce() {
  for (int mask = 0; mask < (1 << n); mask++) {
    long long g[2]{0, 0};
    for (int i = 0; i < (n); i++) {
      int idx = (mask >> i) & 1;
      g[idx] = gcd(g[idx], arr[i].first);
    }
    if (g[0] == 1 && g[1] == 1) {
      cout << "YES\n";
      for (int i = 0; i < (n); i++) cout << 1 + ((mask >> i) & 1) << " ";
      cout << endl;
      return;
    }
  }
  cout << "NO\n";
}
vector<long long> getFactors(long long num) {
  vector<long long> res;
  for (long long i = 2; i * i <= num; i++)
    if (num % i == 0) {
      while (num % i == 0) num /= i;
      res.push_back(i);
    }
  if (num != 1) res.push_back(num);
  return res;
}
bool touse[100000];
int amt[2][9];
vector<int> v;
vector<long long> f[2];
long long num[2];
int res[100000], c[100000][2];
map<tuple<int, int, int>, pair<int, int> > dp;
void solve() {
  pair<int, int> dp[((int)(v).size()) + 1][1 << ((int)(f[0]).size())]
                   [1 << ((int)(f[1]).size())];
  for (int i = 0; i < (((int)(v).size()) + 1); i++)
    for (int j = 0; j < (1 << ((int)(f[0]).size())); j++)
      for (int k = 0; k < (1 << ((int)(f[1]).size())); k++)
        dp[i][j][k] = make_pair(-1, -1);
  dp[0][0][0] = make_pair(0, 0);
  for (int i = 0; i < (((int)(v).size())); i++)
    for (int j = 0; j < (1 << ((int)(f[0]).size())); j++)
      for (int k = 0; k < (1 << ((int)(f[1]).size())); k++)
        if (dp[i][j][k] != make_pair(-1, -1)) {
          dp[i + 1][j | c[v[i]][0]][k] = make_pair(j, k);
          dp[i + 1][j][k | c[v[i]][1]] = make_pair(j, k);
        }
  if (dp[((int)(v).size())][(1 << ((int)(f[0]).size())) - 1]
        [(1 << ((int)(f[1]).size())) - 1] != make_pair(-1, -1)) {
    vector<int> g;
    pair<int, int> curr = make_pair((1 << ((int)(f[0]).size())) - 1,
                                    (1 << ((int)(f[1]).size())) - 1);
    for (int i = (((int)(v).size())) - 1; i >= 0; i--) {
      pair<int, int> prev = dp[i + 1][curr.first][curr.second];
      if (prev.first != curr.first)
        g.push_back(0);
      else
        g.push_back(1);
      curr = prev;
    }
    reverse((g).begin(), (g).end());
    for (int i = 0; i < (((int)(v).size())); i++) res[arr[v[i]].second] = g[i];
    res[arr[0].second] = 0;
    res[arr[1].second] = 1;
    for (int i = (2); i < (n); i++)
      if (!touse[i]) res[arr[i].second] = 0;
    cout << "YES\n";
    for (int i = 0; i < (n); i++) cout << res[i] + 1 << " ";
    cout << "\n";
    exit(0);
  }
}
void attempt() {
  for (int i = 0; i < (2); i++) num[i] = a[i];
  for (int i = 0; i < (2); i++) f[i] = getFactors(num[i]);
  for (int i = 0; i < (n); i++) touse[i] = 0;
  int numF = ((int)(f[0]).size()) + ((int)(f[1]).size());
  assert(((int)(f[0]).size()) <= 9);
  assert(((int)(f[1]).size()) <= 9);
  for (int i = 0; i < (2); i++)
    for (int j = 0; j < (((int)(f[i]).size())); j++) amt[i][j] = 0;
  for (int i = (2); i < (n); i++) {
    c[i][0] = c[i][1] = 0;
    for (int k = 0; k < (2); k++)
      for (int j = 0; j < (((int)(f[k]).size())); j++) {
        if (a[i] % f[k][j] != 0) {
          c[i][k] |= (1 << j);
          if (amt[k][j] < numF) {
            touse[i] = 1;
            amt[k][j]++;
          }
        }
      }
  }
  v.clear();
  for (int i = (2); i < (n); i++)
    if (touse[i]) v.push_back(i);
  assert(((int)(v).size()) <= 324);
  solve();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < (n); i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  if (n <= 20) {
    bruteforce();
    return 0;
  }
  srand(time(NULL));
  for (int reps = 0; reps < (15); reps++) {
    random_shuffle(arr, arr + n);
    for (int i = 0; i < (n); i++) a[i] = arr[i].first;
    attempt();
  }
  cout << "NO\n";
}
