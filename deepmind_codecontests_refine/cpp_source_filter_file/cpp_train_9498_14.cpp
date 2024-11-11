#include <bits/stdc++.h>
using namespace std;
char rev(char x) {
  char res = 0;
  res |= (((x & 0x80) >> 7) | ((x & 0x01) << 7));
  res |= (((x & 0x40) >> 5) | ((x & 0x02) << 5));
  res |= (((x & 0x20) >> 3) | ((x & 0x04) << 3));
  res |= (((x & 0x10) >> 1) | ((x & 0x08) << 1));
  return res;
}
int main() {
  char line[100];
  cin.getline(line, 100);
  char prev = 0;
  int len = strlen(line);
  for (int i = 0; i < len; i++) {
    char c = line[i];
    char res = rev(c);
    cout << ((unsigned short)(prev - res) % 256) << endl;
    prev = res;
  }
  return 0;
}
