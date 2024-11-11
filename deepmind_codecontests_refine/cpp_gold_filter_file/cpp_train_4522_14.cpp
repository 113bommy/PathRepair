#include <bits/stdc++.h>
using namespace std;
map<int, string> m;
vector<int> ans;
int main() {
  string s1, s2;
  int sx, sy, ex, ey, i;
  cin >> s1 >> s2;
  sx = s1[0] - 97;
  sy = s1[1] - 48;
  ex = s2[0] - 97;
  ey = s2[1] - 48;
  while (sx != ex || sy != ey) {
    if (sx < ex && sy > ey) {
      ans.push_back(1);
      sx++;
      sy--;
    } else if (sx > ex && sy > ey) {
      ans.push_back(2);
      sx--;
      sy--;
    } else if (sx < ex && sy < ey) {
      ans.push_back(3);
      sx++;
      sy++;
    } else if (sx > ex && sy < ey) {
      ans.push_back(4);
      sx--;
      sy++;
    } else if (sx == ex && sy < ey) {
      ans.push_back(5);
      sy++;
    } else if (sx == ex && sy > ey) {
      ans.push_back(6);
      sy--;
    } else if (sy == ey && sx < ex) {
      ans.push_back(7);
      sx++;
    } else if (sy == ey && sx > ex) {
      ans.push_back(8);
      sx--;
    }
  }
  m[1] = "RD";
  m[2] = "LD";
  m[3] = "RU";
  m[4] = "LU";
  m[5] = "U";
  m[6] = "D";
  m[7] = "R";
  m[8] = "L";
  cout << ans.size() << endl;
  for (i = 0; i < ans.size(); i++) cout << m[ans[i]] << endl;
  return 0;
}
