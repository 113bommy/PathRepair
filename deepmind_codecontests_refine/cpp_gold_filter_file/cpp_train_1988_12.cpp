#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n;
  cout << "? " << 1 << endl;
  cin >> a;
  cout << "? " << 1 + n / 2 << endl;
  cin >> b;
  if (abs((b - a)) % 2 == 1) {
    cout << "! -1" << endl;
    return 0;
  }
  if (b == a) {
    cout << "! " << 1 << endl;
    return 0;
  }
  int l = 1, r = n / 2;
  while (r - l > 1) {
    int mid = (l + r) / 2, aa, bb;
    cout << "? " << mid << endl;
    cin >> aa;
    cout << "? " << mid + n / 2 << endl;
    cin >> bb;
    if (a - b < 0) {
      if (aa - bb < 0)
        l = mid;
      else if (aa - bb > 0)
        r = mid;
      else if (aa == bb) {
        cout << "! " << mid << endl;
        return 0;
      }
    } else {
      if (aa - bb < 0)
        r = mid;
      else if (aa - bb > 0)
        l = mid;
      else if (aa == bb) {
        cout << "! " << mid << endl;
        return 0;
      }
    }
  }
  cout << "! " << r << endl;
}
