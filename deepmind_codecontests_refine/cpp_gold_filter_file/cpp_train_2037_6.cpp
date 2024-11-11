#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T BM(T p, T e, T M) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T mdINV(T a, T M) {
  return BM(a, M - 2, M);
}
template <class T>
inline T PW(T p, T e) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p);
    p = (p * p);
  }
  return (T)ret;
}
template <class T>
string NTS(T Number) {
  stringstream ss;
  ss << Number;
  return ss.str();
}
template <class T>
T stringtonumber(const string &Text) {
  istringstream ss(Text);
  T result;
  return ss >> result ? result : 0;
}
template <class T>
bool ISLEFT(T a, T b, T c) {
  if (((a.first.first - b.first.first) * (b.second.second - c.second.second) -
       (b.first.first - c.first.first) * (a.second.second - b.second.second)) <
      0.0)
    return 1;
  else
    return 0;
}
int n, k;
vector<int> v[300ll + 2];
long long int dp[102][44];
void go(int u, int p) {
  dp[u][0] = 1;
  dp[u][k + 1] = 1;
  for (int i = 0; i < v[u].size(); i++) {
    int first = v[u][i];
    if (first == p) continue;
    go(first, u);
    long long int kop[44];
    memset(kop, 0, sizeof kop);
    for (int j = 0; j <= k * 2; j++) {
      for (int l = 0; l <= k * 2; l++) {
        if (j + l <= k * 2) {
          kop[min(j, l + 1)] =
              (kop[min(j, l + 1)] + dp[u][j] * dp[first][l]) % 1000000007;
        } else {
          kop[max(j, l + 1)] =
              (kop[max(j, l + 1)] + dp[u][j] * dp[first][l]) % 1000000007;
        }
      }
    }
    for (int j = 0; j <= k * 2; j++) dp[u][j] = kop[j];
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n - 1; i++) {
    int first, second;
    scanf("%d%d", &first, &second);
    v[first].push_back(second);
    v[second].push_back(first);
  }
  go(1, -1);
  int ans = 0;
  for (int i = 0; i <= k; i++) {
    ans += dp[1][i];
    if (ans >= 1000000007) ans -= 1000000007;
  }
  printf("%d", ans);
  return 0;
}
