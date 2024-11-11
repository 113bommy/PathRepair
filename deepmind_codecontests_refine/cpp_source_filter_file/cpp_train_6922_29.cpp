#include <bits/stdc++.h>
using namespace std;
bool y = 0;
int main() {
  long long A, B, k, m;
  cin >> A >> B >> k >> m;
  long long a[A], b[B];
  for (int i = 0; i < A; i++) cin >> a[i];
  for (int i = 0; i < B; i++) cin >> b[i];
  sort(a, a + A);
  sort(b, b + B);
  reverse(b, b + B);
  if (a[A - 1] >= b[m - 1]) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
}
