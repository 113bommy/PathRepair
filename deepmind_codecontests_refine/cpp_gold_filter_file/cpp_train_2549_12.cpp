#include <bits/stdc++.h>
using namespace std;
set<string> st;
string s, a[31];
void Photo() {
  a[1] = "a";
  a[2] = "b";
  a[3] = "c";
  a[4] = "d";
  a[5] = "e";
  a[6] = "f";
  a[7] = "g";
  a[8] = "h";
  a[9] = "i";
  a[10] = "j";
  a[11] = "k";
  a[12] = "l";
  a[13] = "m";
  a[14] = "n";
  a[15] = "o";
  a[16] = "p";
  a[17] = "q";
  a[18] = "r";
  a[19] = "s";
  a[20] = "t";
  a[21] = "u";
  a[22] = "v";
  a[23] = "w";
  a[24] = "x";
  a[25] = "y";
  a[26] = "z";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Photo();
  cin >> s;
  int k = s.size();
  for (int i = 0; i <= k; ++i)
    for (int j = 1; j <= 26; ++j) {
      s.insert(i, a[j]);
      st.insert(s);
      s.erase(i, 1);
    }
  cout << st.size();
  return 0;
}
