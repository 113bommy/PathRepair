#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string str;
    cin >> str;
    int N = str.length();
    if (N == 1) {
      if (str[0] == '0') {
        printf("red\n");
      } else
        printf("cyan\n");
    } else {
      int sum = 0;
      int zc, ec;
      zc = ec = 0;
      for (int i = 0; i < str.length(); i++) {
        int x = str[i] - '0';
        if (x == 0) zc++;
        if (x % 2 == 0) ec++;
        sum += x;
      }
      if (zc && (ec >= 2) && (!(sum % 3)))
        printf("red\n");
      else
        printf("cyan\n");
    }
  }
}
