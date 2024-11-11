#include <bits/stdc++.h>
using namespace std;
long long arr[27];
char str[100005];
long long sums[100005];
map<pair<int, long long>, int> mp;
int main() {
  for (int i = 0; i < 26; i++) {
    cin >> arr[i];
  }
  cin >> str;
  long long cnt = 0;
  int n = (int)strlen(str);
  for (int i = 1; i <= n; i++) {
    if (i != 1) cnt += mp[make_pair(str[i - 1] - 'a', sums[i - 1])];
    sums[i] = sums[i - 1] + (arr[str[i - 1] - 'a']);
    mp[make_pair(str[i - 1] - 'a', sums[i])]++;
  }
  cout << cnt << endl;
  return 0;
}
