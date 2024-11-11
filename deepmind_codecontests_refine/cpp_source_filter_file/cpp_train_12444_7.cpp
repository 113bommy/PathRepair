#include <bits/stdc++.h>
using namespace std;
int main() {
  int plus = 0, minus = 0;
  string s;
  getline(cin, s);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '+')
      plus++;
    else if (s[i] == '-')
      minus++;
  }
  int final = 0;
  int r = s.find("=");
  r += 2;
  for (int i = r; i < s.size(); i++) {
    final *= 10;
    final += int(s[i] - '0');
  }
  int a[100], b[100];
  for (int i = 0; i < 100; i++) a[i] = 1, b[i] = 1;
  int maxi = final + (final * plus) - minus;
  int mini = 1 + plus - (minus * final);
  int finalans = 1 + plus - minus;
  int ans = 1;
  int i = 0;
  if (final <= maxi and final >= mini) {
    cout << "Possible\n";
    while (finalans < final) {
      if (ans < final)
        ans++, finalans++;
      else {
        if (a[i] < final)
          a[i]++, finalans++;
        else
          i++, a[i]++, finalans++;
      }
    }
    while (finalans > final) {
      if (b[i] > final)
        i++;
      else
        b[i]++, finalans--;
    }
    cout << ans;
    r = 0;
    int p = 0;
    for (int i = 2; i < s.size(); i++) {
      if (s[i] == '+') {
        cout << " + ";
        cout << a[r];
        r++;
      } else if (s[i] == '-') {
        cout << " - ";
        cout << b[p];
        p++;
      }
    }
    cout << " = ";
    cout << final;
  } else
    cout << "Impossible";
  return 0;
}
