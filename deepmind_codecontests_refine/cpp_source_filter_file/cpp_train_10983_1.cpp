#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 0, A = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= 'a')
      a++;
    else
      A++;
  }
  if (a >= A) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] <= 'a') s[i] += 32;
    }
  } else {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= 'a') s[i] -= 32;
    }
  }
  cout << s;
}
