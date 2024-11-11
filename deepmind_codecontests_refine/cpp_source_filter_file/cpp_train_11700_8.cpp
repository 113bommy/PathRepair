#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y;
string s, t;
int main() {
  cin >> n >> s >> t;
  int num1 = 0, num2 = 0;
  n *= 2;
  int n3 = 0, n4 = 0, n5 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i] && s[i] == '1') n3++;
    if (s[i] == '0' && t[i] == '1') n4++;
    if (s[i] == '1' && t[i] == '0') n5++;
  }
  bool tu = true;
  while (n3 > 0 || n4 > 0 || n5 > 0) {
    if (tu) {
      if (n3) {
        n3--;
        num1++;
      } else if (n5 < n4) {
        if (n5) {
          n5--;
          num1++;
        } else if (n4) {
          n4--;
        }
      } else {
        if (n4) {
          n4--;
        } else if (n5) {
          n5--;
          num1++;
        }
      }
    } else {
      if (n3) {
        n3--;
        num2++;
      }
      if (n4 < n5) {
        if (n4) {
          n4--;
          num2++;
        } else if (n5) {
          n5--;
        }
      } else {
        if (n5) {
          n5--;
        } else if (n4) {
          n4--;
          num2++;
        }
      }
    }
    tu = !tu;
  }
  if (num1 > num2) {
    cout << "First" << endl;
  } else if (num1 == num2)
    cout << "Draw" << endl;
  else
    cout << "Second" << endl;
}
