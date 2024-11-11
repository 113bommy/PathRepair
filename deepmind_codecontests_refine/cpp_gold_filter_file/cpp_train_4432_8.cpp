#include <bits/stdc++.h>
using namespace std;
string ys = "YES", no = "NO", st;
int di[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dj[8] = {0, -1, 0, 1, 1, 1, -1, -1};
const int N = 1.5 * 10000000 + 16;
const long long int OO = 1e18;
long long int mod = 1e9 + 7;
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fast();
  int q;
  q = 1;
  while (q--) {
    long long n;
    cin >> n;
    --n;
    char a;
    cin >> a;
    string mp = "#fedabc";
    n = n - (n % 4) + (n % 2);
    long long ans = n + 6 * ((n + 1) / 2) + mp.find(a);
    return cout << ans << "\n", 0;
  }
}
