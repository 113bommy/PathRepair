#include <bits/stdc++.h>
using namespace std;
char reverse(char c) {
  char res = 0;
  for (int i = 0; i < 8; i++) {
    res <<= 1;
    res |= (c & 1);
    c >>= 1;
  }
  return res;
}
int main() {
  char buf[100];
  cin.getline(buf, sizeof(buf));
  string s(buf);
  char next = 0;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    c = reverse(c);
    char tmp2 = c;
    c = (next - c) % 256;
    next = tmp2;
    int out = c;
    if (out < 0) out += 256;
    cout << out << endl;
  }
}
