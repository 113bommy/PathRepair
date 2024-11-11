#include <bits/stdc++.h>
int dd[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
using namespace std;
char a[200005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int zero = 0, one = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == '(') {
      if (zero == one) {
        cout << 0;
        zero++;
      } else {
        cout << 1;
        one++;
      }
    }
    if (a[i] == ')') {
      if (zero >= one) {
        cout << 0;
        zero--;
      } else {
        cout << 1;
        one--;
      }
    }
  }
  cout << endl;
  return 0;
}
