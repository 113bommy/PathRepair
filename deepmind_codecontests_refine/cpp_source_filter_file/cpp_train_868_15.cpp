#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
const int N = 100100;
const int F[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
string s[N];
int ns;
vector<int> a;
int GetTime(string s) {
  int se, mi, ho, day, mon;
  se = (int(s[17]) - 48) * 10 + int(s[18]) - 48;
  mi = (int(s[14]) - 48) * 10 + int(s[15]) - 48;
  ho = (int(s[11]) - 48) * 10 + int(s[12]) - 48;
  day = (int(s[8]) - 48) * 10 + int(s[9]) - 48;
  mon = F[(int(s[5]) - 48) * 10 + int(s[6]) - 48];
  return (se + mi * 60 + ho * 3600 + day * 24 * 3600 + mon * 24 * 3600);
}
int main() {
  int n, m;
  scanf("%d%d\n", &n, &m);
  while (getline(cin, s[ns++])) a.push_back(GetTime(s[ns - 1]));
  for (int i = m - 1; i < a.size(); i++)
    if (a[i] - a[i - m + 1] < n) {
      for (int j = 0; j < 19; j++) cout << s[i][j];
      return 0;
    }
  cout << -1 << "\n";
}
