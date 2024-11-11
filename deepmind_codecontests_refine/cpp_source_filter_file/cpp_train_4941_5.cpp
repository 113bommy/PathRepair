#include <bits/stdc++.h>
const double EPS = 1e-24;
const long long int MOD = 1000000007ll;
const double PI = 3.14159265359;
int INF = 2147483645;
template <class T>
T Max2(T a, T b) {
  return a < b ? b : a;
}
template <class T>
T Min2(T a, T b) {
  return a < b ? a : b;
}
template <class T>
T Max3(T a, T b, T c) {
  return Max2(Max2(a, b), c);
}
template <class T>
T Min3(T a, T b, T c) {
  return Min2(Min2(a, b), c);
}
template <class T>
T Max4(T a, T b, T c, T d) {
  return Max2(Max2(a, b), Max2(c, d));
}
template <class T>
T Min4(T a, T b, T c, T d) {
  return Min2(Min2(a, b), Max2(c, d));
}
template <class T>
void Swap(T& a, T& b) {
  T temp;
  temp = a;
  a = b;
  b = temp;
}
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  long long int N;
  cin >> N;
  long long int F = 0;
  for (;; F++)
    if (3 * ((F * (F + 1)) / 2) - F > N) break;
  F--;
  long long int ans = 0;
  long long int x = 3 * ((F * (F + 1)) / 2) - F;
  for (long long int i = F; i >= 1; i--)
    if ((x - 3 * ((i * (i + 1)) / 2) + i) % 3 == 0) ans++;
  cout << ans;
  return 0;
}
