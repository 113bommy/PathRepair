#include <bits/stdc++.h>
using namespace std;
const int inf = 2147483647;
const double PI = acos(-1.0);
const double e = 2.718281828459;
const int mod = 1000000007;
int a[30];
char s[100005];
vector<int> vc[30];
int v[100005];
map<long long, long long> mp[30];
int main() {
  int i, j;
  for (i = 0; i < 26; ++i) scanf("%d", &a[i]);
  scanf("%s", s + 1);
  long long ans = 0;
  for (i = 1; s[i]; ++i) {
    v[i] = v[i - 1] + a[s[i] - 'a'];
    ans += mp[s[i] - 'a'][v[i - 1]];
    mp[s[i] - 'a'][v[i]]++;
  }
  cout << ans << endl;
}
