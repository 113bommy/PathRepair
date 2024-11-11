#include <bits/stdc++.h>
using namespace std;
long long nCr(int n, int r) {
  if (r > n - r) r = n - r;
  long long ans = 1;
  int i;
  for (i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long a, b, c, d, e, g, h, n, t, f, k, l, m,
      f1 = 0, flag = 0, flag1 = 0, co = 0, co1 = 0, co2 = 0, arr1[100001] = {0},
      arr[100001] = {0}, sum = 0, sum1 = 0, ma = 0, mi = 1000000000000000001;
  long long co3 = 0, co4 = 0, co5 = 0, co6 = 0, co7 = 0, co8 = 0;
  double pi = 2 * acos(0.0);
  string str, str1, str2, str3;
  char ch;
  vector<long long> v;
  vector<long long> v1;
  vector<string> vs;
  vector<string> vs1;
  map<int, int> mp;
  set<char> s;
  set<long long> s1;
  set<long long>::iterator it;
  queue<long long> q;
  int x[] = {1, 1, 1, 0, 0, -1, -1, -1};
  int y[] = {0, 1, -1, 1, -1, 1, -1, 0};
  cin >> a >> b;
  for (int i = 0; i < a; i++) {
    cin >> c;
    v.push_back(c);
  }
  sort(v.begin(), v.end());
  if (b == 0)
    d = v[0] - 1;
  else
    d = v[b - 1];
  for (int i = 0; i < v.size(); i++) {
    if (v[i] <= d) co++;
  }
  if (co == b && (co >= 1 && co <= 1000000000))
    cout << d << endl;
  else
    cout << -1 << endl;
  return 0;
}
