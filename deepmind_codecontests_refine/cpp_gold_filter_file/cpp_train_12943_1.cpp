#include <bits/stdc++.h>
using namespace std;
long long compute(long long u) {
  if (u % 4 == 1)
    return 1;
  else if (u % 4 == 2)
    return u + 1;
  else if (u % 4 == 3)
    return 0;
  else if (u % 4 == 0)
    return u;
}
int main() {
  long long res = 0, a, b;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    res ^= compute(a - 1);
    res ^= compute(a + b - 1);
  }
  if (!res)
    cout << "bolik" << endl;
  else
    cout << "tolik" << endl;
}
