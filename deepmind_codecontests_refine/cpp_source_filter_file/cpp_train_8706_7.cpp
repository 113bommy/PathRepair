#include <bits/stdc++.h>
using namespace std;
const int N = 1502;
const int MOD = 1e9 + 7;
const int bm = 1;
int n, m;
int d[10];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> d[1] >> d[2] >> d[3];
  sort(d + 1, d + 4);
  if (d[1] == d[3] && d[1] == 3)
    cout << "YES";
  else if (d[1] == d[2] && d[2] == 2)
    cout << "YES";
  else if (d[1] == 1)
    cout << "YES";
  else if (d[1] == d[2] && d[2] == 2 && d[3] == 4)
    cout << "YES";
  else
    cout << "NO";
}
