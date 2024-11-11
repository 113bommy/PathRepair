#include <bits/stdc++.h>
using namespace std;
int dx[8] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int ini() {
  int x;
  scanf("%d", &x);
  return x;
}
long long inl() {
  long long x;
  scanf("%lld", &x);
  return x;
}
const int N = (int)2e5 + 5;
const int inf = (int)1e9 + 7;
const double pi = 2 * acos(0.0);
int a[N];
int main() {
  int x;
  cin >> x;
  if (x == 2)
    cout << 2 << endl;
  else {
    cout << x - 1 << endl;
  }
  return 0;
}
