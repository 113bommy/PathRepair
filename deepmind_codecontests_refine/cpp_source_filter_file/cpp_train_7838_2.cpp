#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, aa = 0, c = 0;
  cin >> n;
  int a[12];
  for (int i = 0; i < 12; i++) cin >> a[i];
  sort(a, a + 12);
  reverse(a, a + 12);
  if (n == 0) {
    cout << "0";
    return 0;
  } else
    for (int i = 0; i < 12; i++) {
      aa += a[0];
      c++;
      if (aa >= n) {
        cout << c;
        return 0;
      }
    }
  cout << "-1";
  return 0;
}
