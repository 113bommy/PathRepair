#include <bits/stdc++.h>
using namespace std;
int l, b, f, n, a[100], pos[100];
bool p[100001];
int main() {
  cin >> l >> b >> f >> n;
  for (int k = 0; k < n; k++) {
    int type;
    cin >> type;
    if (type == 1) {
      cin >> a[k];
      for (int i = 0; i <= l; i++) {
        if (i + a[k] > l) {
          cout << -1 << endl;
          break;
        }
        int L = i - b;
        int R = i + a[k] + f;
        bool good = true;
        for (int j = L; j < R; j++)
          if (j >= 0 && j <= l && p[j]) {
            good = false;
            break;
          }
        if (good) {
          for (int j = L + b; j < R - f; j++) p[j] = true;
          pos[k] = L + b;
          cout << L + b << endl;
          break;
        }
      }
    } else {
      int num;
      cin >> num;
      num--;
      for (int i = pos[num]; i < pos[num] + a[num]; i++) p[i] = false;
    }
  }
  return 0;
}
