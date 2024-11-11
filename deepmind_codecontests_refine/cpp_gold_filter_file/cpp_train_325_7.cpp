#include <bits/stdc++.h>
long long A, B, C, D, E, F, I, J, K, M, N, O, P, Q, R, S, T, U, V, X, Y, Z;
using namespace std;
const string MINUSINF = "-";
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
void chmax(string& a, string b) {
  if (a == MINUSINF)
    a = b;
  else if (a.size() < b.size())
    a = b;
  else if (a.size() == b.size()) {
    if (a < b) a = b;
  }
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int GCD(int a, int b) { return b ? GCD(b, a % b) : a; }
stack<long long> sta;
queue<long long> que;
deque<long long> dque;
set<string> s_set;
long long sum, sum1, sum2, sum3, sum4;
long long flg, flg1, flg2, flg3, cnt, cnt1, cnt2, cnt3, cnt4;
long long wk, wk1, wk2, wk3, wk4;
long long ans;
bool f;
long long weight[110], value[110];
long long a[100010][3];
long long n, h[100005];
vector<long long> p, c;
int vis[200001];
vector<string> first;
int Left[2100][2100], Right[2100][2100], Up[2100][2100], Down[2100][2100];
long long match[10] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
vector<long long> box;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  long long max, max1;
  long long min, min1;
  sum = sum1 = sum2 = sum3 = sum4 = 0;
  flg = flg1 = flg2 = flg3 = cnt = cnt1 = cnt2 = cnt3 = cnt4 = 0;
  max = max1 = 0;
  wk = wk1 = wk2 = wk3 = wk4 = 0;
  ans = 0;
  min = min1 = 1e18 + 5;
  std::cin >> N >> X >> Y;
  string s, t;
  std::cin >> s;
  for (long long i = s.length() - 1; i >= s.length() - 1 - X + 1; i--) {
    if (cnt == Y) {
      if (s[i] == '0') {
        ans++;
      }
    } else {
      if (s[i] == '1') {
        ans++;
      }
    }
    cnt++;
  }
  if (1) {
    printf("%lld", ans);
  } else {
  }
  return 0;
  return 0;
}
