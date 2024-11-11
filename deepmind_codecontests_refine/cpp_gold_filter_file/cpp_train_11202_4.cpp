#include <bits/stdc++.h>
using namespace std;
int main() {
  char first[200];
  char ch[27];
  char chh[27];
  char sc;
  int flag = 0;
  string in;
  string ans;
  cin >> ch;
  cin >> chh;
  cin >> in;
  for (int i = 0; i < 26; ++i) {
    first[ch[i]] = chh[i];
  }
  for (int i = 0; i < in.size(); ++i) {
    if (in[i] < 97 && in[i] > 57) {
      in[i] += 32;
      sc = first[in[i]];
      sc -= 32;
    } else if (in[i] <= 57)
      sc = in[i];
    else
      sc = first[in[i]];
    ans += sc;
  }
  cout << ans << endl;
  return 0;
}
