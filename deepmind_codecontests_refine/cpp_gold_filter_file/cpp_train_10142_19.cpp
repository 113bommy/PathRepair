#include <bits/stdc++.h>
using namespace std;
void GO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const long long N = 1e5 + 100, OO = 1e18;
int mx = -OO, mn = OO;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char arr[1050][1050];
int main() {
  GO();
  int a, b;
  cin >> a >> b;
  int fi = 0, sec = 0, dr = 0;
  for (int i = 1; i <= 6; ++i) {
    if (abs(a - i) < abs(b - i))
      fi++;
    else if (abs(a - i) > abs(b - i))
      sec++;
    else
      dr++;
  }
  cout << fi << " " << dr << " " << sec;
  return 0;
}
