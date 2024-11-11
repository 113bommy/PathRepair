#include <bits/stdc++.h>
using namespace std;
int val[26];
char str[100020];
map<int, long long> mp[26];
int main() {
  for (int i = 0; i < 26; i++) scanf("%d", &val[i]);
  scanf("%s", str);
  long long sum = 0, ans = 0;
  for (int i = 0; str[i]; i++) {
    ans += mp[str[i] - 'a'][sum];
    sum += val[str[i] - 'a'];
    mp[str[i] - 'a'][sum]++;
  }
  printf("%I64d\n", ans);
}
