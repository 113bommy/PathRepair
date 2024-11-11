#include <bits/stdc++.h>
using namespace std;
char c[1000001];
int a[1000001];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  int s1 = 0, s2 = 0;
  for (int i = 1; i <= n; i++) {
    if (c[i] == '(') {
      if (s1 <= s2) {
        s1++;
        a[i] = 0;
      } else {
        s2++;
        a[i] = 1;
      }
    }
    if (c[i] == ')') {
      if (s1 >= s2) {
        s1--;
        a[i] = 0;
      } else {
        s2--;
        a[i] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i];
  }
  return 0;
}
