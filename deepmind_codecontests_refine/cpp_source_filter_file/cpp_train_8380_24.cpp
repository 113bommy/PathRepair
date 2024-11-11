#include <bits/stdc++.h>
using namespace std;
bool pos[505][505];
vector<int> kadali;
int main(void) {
  int x, y, x0, y0, sum;
  cin >> x >> y >> x0 >> y0;
  string str;
  cin >> str;
  pos[x0][y0] = true;
  kadali.push_back(1);
  sum = 1;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'U') x0--;
    if (str[i] == 'D') x0++;
    if (str[i] == 'L') y0--;
    if (str[i] == 'R') y0++;
    if (x0 < 1) x0 = 1;
    if (y0 < 1) y0 = 1;
    if (x0 > x) x = x;
    if (y0 > y) y0 = y;
    if (i < str.size() - 1) {
      if (pos[x0][y0])
        kadali.push_back(0);
      else {
        kadali.push_back(1);
        sum++;
        pos[x0][y0] = true;
      }
    } else {
      if (pos[x0][y0])
        kadali.push_back(x * y - sum);
      else {
        pos[x0][y0] = true;
        kadali.push_back(x * y - sum);
        sum++;
      }
    }
  }
  for (auto kandhi : kadali) cout << kandhi << " ";
  cout << endl;
}
