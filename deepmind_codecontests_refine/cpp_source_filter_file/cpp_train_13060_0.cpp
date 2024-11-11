#include <bits/stdc++.h>
using namespace std;
const long double PI =
    3.14159265358979323846264338327950288419716939937510582097494459230;
const long long MOD = 1000000007LL;
const long long INF = 1e9;
const long long LINF = 1e18;
const long double EPS = 1e-9;
const long double GOLD = ((1 + sqrt(5)) / 2);
template <class T>
int getbit(T s, int i) {
  return (s >> 1) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcount(s);
}
long long n;
bool isComp(long long z) {
  for (long long i = 2; i <= sqrt(z); i++) {
    if (z % i == 0) return true;
  }
  return false;
}
void VarInput() { cin >> n; }
void ProSolve() {
  for (long long i = 4; i < n / 2; i++) {
    if (isComp(i) && isComp(n - i)) {
      cout << i << " " << n - i;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  VarInput();
  ProSolve();
  return 0;
}
