#include <bits/stdc++.h>
using namespace std;
int main() {
  int s = 0, s1 = 0;
  string k;
  cin >> k;
  int i;
  for (i = 0; i < k.size(); i++) {
    if (k[i] == 'a') {
      s++;
    }
    if (k[i] != 'a') {
      s1++;
    }
  }
  if (((s1 + s) / 2) < s) {
    cout << s1 + s;
  }
  if (((s1 + s) / 2) >= s) {
    cout << (s + s) - 1;
  }
}
