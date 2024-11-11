#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
const long long int mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
int n, m;
long long int arr[15];
int guess[15];
set<long long int> temp1, temp2, ans;
void rec(long long int b, int picked, int i, long long int num) {
  if (b < 0) {
    if (picked == guess[i]) temp1.insert(num);
  } else {
    if (picked < guess[i])
      rec(b - 1, picked + 1, i, num | (((arr[i] >> b) & 1LL) << b));
    rec(b - 1, picked, i, num | (!((arr[i] >> b) & 1LL) << b));
  }
}
void cp() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    bitset<35> x;
    cin >> x >> guess[i];
    arr[i] = x.to_ullong();
  }
  n--;
  rec(n, 0, 0, 0);
  ans = temp1;
  for (int i = 1; i < m; i++) {
    temp1.clear();
    rec(n, 0, i, 0);
    temp2.clear();
    for (long long int x : ans)
      if (temp1.find(x) != temp1.end()) temp2.insert(x);
    ans = temp2;
  }
  cout << ((int)ans.size()) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  while (t--) {
    cp();
  }
  return 0;
}
