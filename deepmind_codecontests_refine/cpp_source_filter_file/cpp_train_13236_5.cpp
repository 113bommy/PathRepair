#include <bits/stdc++.h>
using namespace std;
int main() {
  const string T = "RRRRPSSPRR";
  string s, t;
  for (int i = 0; i < 10; i++) {
    printf("%c\n", T[i]);
    fflush(stdout);
    string verdict;
    getline(cin, verdict);
    s += (verdict == "ai" ? '0' : '1');
  }
  if (s == "0000100100") t = "PPPPPPPPPP";
  if (s == "0000011000") t = "SSSSSSSSSS";
  if (s == "1111000011") t = "RRRRRRRRRR";
  if (s == "0010000010") t = "PSRPSRPSRP";
  if (s == "0000110000") t = "PSRPSRPSRP";
  if (s == "0000000110") t = "SPRSPRSPRS";
  for (int i = 0; i < 10; i++) {
    printf("%c\n", t[i]);
    fflush(stdout);
    string verdict;
    getline(cin, verdict);
  }
  return 0;
}
