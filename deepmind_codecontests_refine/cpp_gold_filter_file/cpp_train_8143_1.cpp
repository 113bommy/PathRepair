#include <bits/stdc++.h>
using namespace std;
int main() {
  int h = 1000003;
  char s[8] = {'>', '<', '+', '-', '.', ',', '[', ']'};
  string b[8] = {"1000", "1001", "1010", "1011",
                 "1100", "1101", "1110", "1111"};
  string x, y;
  int c = 0, t = 1;
  cin >> x;
  for (int i = 0; i < x.length(); i++) {
    for (int j = 0; j < 8; j++) {
      if (x[i] == s[j]) y.append(b[j]);
    }
  }
  for (int w = 1; w <= y.length(); w++) {
    c = (c + (y[y.length() - w] - '0') * t) % h;
    t *= 2;
    t %= h;
    c %= h;
  }
  cout << c << endl;
}
