#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, l = 0, o;
  string s[100];
  for (int i = 0; i < 100; i++)
    s[i] +=
        "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS"
        "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS";
  cin >> k;
  char u;
  if (k % 2) {
    cout << -1 << endl;
    return 0;
  }
  o = k - 1;
  for (int i = 0; i < k / 2; i++) {
    if (i % 2)
      u = 'b';
    else
      u = 'w';
    for (int j = 0; j < k; j++)
      for (int h = 0; h < k; h++)
        if (j >= l && j <= o && h >= l && h <= o) s[j][h] = u;
    l++;
    o--;
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      for (int h = 0; h < k; h++)
        if (s[j][h] != 'S') {
          if (i % 2) {
            if (s[j][h] == 'w')
              cout << 'b';
            else
              cout << 'w';
          } else
            cout << s[j][h];
        }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
