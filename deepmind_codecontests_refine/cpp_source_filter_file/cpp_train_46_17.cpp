#include <bits/stdc++.h>
using namespace std;
int main() {
  long long f = 0, s = 0, t = 0, n;
  cin >> n;
  long long x;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    f ^= x;
  }
  s = f;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", &x);
    s ^= x;
    t ^= x;
  }
  for (int i = 0; i < n - 2; i++) {
    scanf("%d", &x);
    t ^= x;
  }
  cout << s << endl << t;
  return 0;
}
