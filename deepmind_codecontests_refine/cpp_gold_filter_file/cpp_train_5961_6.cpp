#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.);
const double eps = 1e-7;
const int inf = 2147483647;
const int _inf = -2147483648;
const long long int INF = 1e18 + 1;
const int mod = 1e9 + 7;
void delay(int sec);
void solution(void) {
  int n, ans, x, y;
  cin >> n;
  ans = 7 + 3 * (n - 1);
  cout << ans << "\n";
  cout << "0 0\n";
  cout << "0 1\n";
  cout << "1 0\n";
  cout << "1 1\n";
  x = 1, y = 2;
  while (n--) {
    cout << x << " " << y << "\n";
    x++;
    y--;
    cout << x << " " << y << "\n";
    y++;
    cout << x << " " << y << "\n";
    y++;
  }
  return;
}
int main(int argc, char *arv[]) {
  unsigned short int t = 1;
  while (t--) {
    solution();
  }
  return 0;
}
void delay(int sec) {
  int mili_sec = 1000 * sec;
  clock_t start_time = clock();
  while (clock() < start_time + mili_sec)
    ;
  return;
}
