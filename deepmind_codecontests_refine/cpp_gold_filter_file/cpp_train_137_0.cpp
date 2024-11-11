#include <bits/stdc++.h>
using namespace std;
int counter[32];
int k;
string getString() {
  for (int i = (0); i < (int)(32); i++)
    if (counter[i] % k) return "-1";
  string pattern = "";
  for (int i = (0); i < (int)(32); i++) {
    for (int j = (0); j < (int)(counter[i] / k); j++) {
      pattern += (char)('a' + i);
    }
  }
  string res = "";
  for (int i = (0); i < (int)(k); i++) res += pattern;
  return res;
}
int main() {
  memset(counter, 0, sizeof(counter));
  cin >> k;
  char c;
  while (cin >> c) {
    counter[c - 'a']++;
  }
  cout << getString() << endl;
}
