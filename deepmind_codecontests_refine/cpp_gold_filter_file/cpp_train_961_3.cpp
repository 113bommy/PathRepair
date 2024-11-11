#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(10);
  cout.tie(nullptr);
  cin.tie(nullptr);
}
template <class T>
T power(T N, T P) {
  return (P == 0) ? 1 : N * power(N, P - 1);
}
template <class T>
T GCD(T A, T B) {
  return (A % B == 0) ? B : GCD(B, A % B);
}
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const long long INF = 1e18;
const long double PI = acos((long double)-1);
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
bool sort_rev(int a, int b) { return a > b; }
bool sort_(pair<string, int> &p1, pair<string, int> &p2) {
  if (p1.first == p2.first) return p1.second < p2.second;
  return p1.first < p2.first;
}
int main() {
  fastIO();
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    int ara[100005], b[100005], used[100005];
    for (int i = 0; i < n; i++) cin >> ara[i];
    for (int i = 0; i <= n + 1; i++) {
      used[i] = -1;
      b[i] = -1;
    }
    for (int i = 1; i < n; i++) {
      if (ara[i] != ara[i - 1]) {
        b[i] = ara[i - 1];
        used[ara[i - 1]] = 1;
      }
    }
    used[ara[n - 1]] = 1;
    int posUnused = 0;
    for (int i = 0; i < n; i++) {
      if (b[i] == -1) {
        while (used[posUnused] == 1) posUnused++;
        b[i] = posUnused;
        used[posUnused] = 1;
      }
      cout << b[i] << " ";
    }
  }
  return 0;
}
