#include <bits/stdc++.h>
using namespace std;
string in;
bool dpp[2005][2005];
unsigned long long dp2[2005][2005] = {0};
bool ispal(int s, int e) {
  for (; s < e; s++, e--)
    if (in[s] != in[e]) return false;
  return true;
}
int main() {
  cin >> in;
  unsigned long long w = 0;
  for (int ps = 1; ps <= in.length(); ps++)
    for (int i = 0; i <= in.length(); i++)
      dpp[i][ps] = (i + ps > in.length()) ? 0 : ispal(i, i + ps - 1);
  for (int ps = 1; ps <= in.length(); ps++)
    for (int i = in.length(); i >= 0; i--)
      dp2[i][ps] += dp2[i + 1][ps] + dpp[i][ps];
  for (int ps = 1; ps <= in.length(); ps++)
    for (int i = 0; i <= in.length(); i++) dp2[i][ps] += dp2[i][ps - 1];
  for (int ps = 1; ps < in.length(); ps++)
    for (int i = 0; i < in.length() - ps; i++)
      if (dpp[i][ps]) w += dp2[i + ps][in.length()];
  cout << w << endl;
  return 0;
}
