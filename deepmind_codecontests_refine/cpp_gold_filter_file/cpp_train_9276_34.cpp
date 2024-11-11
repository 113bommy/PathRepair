#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
string str, ans, rafi, chk;
map<char, int> m;
queue<int> q;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  int n, i, j, cnt1 = 1, cnt2 = 1, cnt = 0, k, x = 0, y = 0, flag = 0, sum = 0;
  int a, b, c, d, ans = 0, zero = 0, fst = 0, lst = 0, one = 0, mn = INT_MAX,
                  mx = INT_MIN;
  string str;
  cin >> n;
  int chk[104] = {0};
  for (int i = 0; i < n; i++) {
    cin >> x;
    for (int i = 0; i < x; i++) {
      cin >> a;
      chk[a]++;
      mx = max(mx, chk[a]);
    }
  }
  for (int i = 0; i <= 100; i++) {
    if (mx == chk[i]) {
      cout << i << " ";
    }
  }
  cout << endl;
  return 0;
}
