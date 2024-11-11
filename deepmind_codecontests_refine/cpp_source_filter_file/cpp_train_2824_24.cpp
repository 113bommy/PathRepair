#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v2;
vector<long long int> v, v1;
map<char, long long int> m1, m2;
long long int n, i, k, p, j, cnt[100000], a;
string s, s1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  j = 0, p = 0;
  for (i = 1; i < n; i++) {
    if (v[i - 1] == v[i]) {
      cnt[p] = i - j;
      p++;
      j = i;
    }
  }
  cnt[p] = n - 1 - j;
  p++;
  sort(cnt, cnt + p);
  cout << cnt[p - 1] << endl;
  return 0;
}
