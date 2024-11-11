#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:512000000")
using namespace std;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
const int INF = INT_MAX;
const long long INFLL = (long long)1e18;
const double PI = acos(-1.0);
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T>
T abs(T a) {
  return (a > 0 ? a : -a);
}
const int N = (int)1e5 + 5;
int a, b;
int num[105], numx[105];
int main() {
  ios::sync_with_stdio(false);
  cout.setf(ios::fixed | ios::showpoint);
  cout.precision(8);
  time_t start = clock();
  cin >> a >> b;
  if (b == 0) {
    if (a == 1) return !printf("0 0");
    return !printf("-1 -1");
  }
  num[0] = 1;
  numx[0] = 9;
  for (int i = 1; i < a; i++) num[i] = 0, numx[i] = 9;
  int cursumm = 1, i = a - 1;
  while (cursumm < b && i > -1) {
    num[i]++;
    if (num[i] == 9) i--;
    cursumm++;
  }
  int cursum = 9 * a;
  i = a - 1;
  while (cursum > b && i > -1) {
    numx[i]--;
    if (numx[i] == 0) i--;
    cursum--;
  }
  if (num[0] != 0 && cursumm == b)
    for (int i = 0; i < (a); i++) cout << num[i];
  else
    cout << "-1";
  cout << ' ';
  if (numx[0] != 0 && cursum == b)
    for (int i = 0; i < (a); i++) cout << numx[i];
  else
    cout << "-1";
  cout << endl;
  cerr << "Time: " << ((clock() - start) * 1.0 / CLOCKS_PER_SEC) << endl;
  return 0;
}
