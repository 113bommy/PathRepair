#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
map<long long, long long> mp;
map<long long, long long>::iterator it;
long long s[N];
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    mp[x]++, y++, mp[y]--;
  }
  long long l = 0, cnt = 0;
  for (it = mp.begin(); it != mp.end(); it++) {
    s[cnt] += it->first - l;
    l = it->first;
    cnt += it->second;
  }
  for (int i = 1; i <= n; i++) cout << s[i] << " ";
  return 0;
}
