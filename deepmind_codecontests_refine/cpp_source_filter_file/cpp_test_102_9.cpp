#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 4;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int len = s.size();
    int up = 0, down = 0, left = 0, right = 0;
    int xcor = 0, ycor = 0;
    int flag = 0;
    int maxx = 0, minx = 0, miny = 0, maxy = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == 'L')
        xcor--;
      else if (s[i] == 'R')
        xcor++;
      else if (s[i] == 'U')
        ycor++;
      else
        ycor--;
      maxx = max(maxx, xcor);
      minx = min(minx, xcor);
      maxy = max(maxy, ycor);
      miny = min(miny, ycor);
      if (abs(maxx - minx) + 1 > m || abs(maxy - miny) + 1 > n) {
        int x, y;
        if (s[i] == 'L')
          y = m - maxx, x = n + miny;
        else if (s[i] == 'R')
          y = m - maxx - 1, x = n + miny;
        else if (s[i] == 'U')
          x = n + miny, y = m - maxx;
        else if (s[i] == 'D')
          x = n + miny + 1, y = m - maxx;
        cout << x << " " << y << endl;
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cout << n + miny << " " << m - maxx << endl;
    }
  }
  return 0;
}
