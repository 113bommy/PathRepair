#include <bits/stdc++.h>
using namespace std;
long long const N = 1325000;
bool ARR[N];
void fix(unsigned long long a) {
  for (unsigned long long i = a; i < N; i += a) ARR[i] = 1;
}
void rmv(unsigned long long &a, unsigned long long d) {
  while (a % d == 0) a /= d;
  fix(d);
}
void primefix(unsigned long long a) {
  if (a % 2 == 0) rmv(a, 2);
  if (a % 3 == 0) rmv(a, 3);
  for (unsigned long long i = 6; i <= sqrt(a) + 1; i += 6) {
    if (a % (i + 1) == 0) rmv(a, i + 1);
    if (a % (i - 1) == 0) rmv(a, i - 1);
  }
  if (a != 1) fix(a);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  bool x = 0;
  unsigned long long X = 2;
  for (int i = 0; i < n; i++) {
    int in;
    cin >> in;
    if (!x) {
      if (!ARR[in]) {
        cout << in << " ";
        primefix(in);
      } else
        for (unsigned long long j = in; j < N; j++)
          if (!ARR[j]) {
            primefix(j);
            cout << j << " ";
            x = 1;
            break;
          }
    } else
      for (; X < N; X++)
        if (!ARR[X]) {
          primefix(X);
          cout << X << " ";
          break;
        }
  }
}
