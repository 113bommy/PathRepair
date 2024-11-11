#include <bits/stdc++.h>
using namespace std;
int bit[500000];
std::map<long long, long long> mp;
pair<long long, long long> arr[200010];
int query(int temp) {
  int i = temp, ans = 0;
  while (i) {
    ans = max(ans, bit[i]);
    i -= i & (-i);
  }
  return ans;
}
void update(int temp, int value) {
  int i = temp;
  while (i < 200010) {
    bit[i] = max(bit[i], value);
    i = i + (i & (-i));
  }
}
int main() {
  int n, ans = 0, i, temp;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%I64d", &arr[i].first);
    scanf("%I64d", &arr[i].second);
    mp[arr[i].first - arr[i].second];
    mp[arr[i].first + arr[i].second];
  }
  int index = 0;
  i = 0;
  for (std::map<long long, long long>::iterator it = mp.begin(); it != mp.end();
       it++) {
    it->second = index++;
  }
  memset(bit, 0, sizeof(bit));
  sort(arr, arr + n);
  for (i = 0; i < n; i++) {
    temp = mp[arr[i].first - arr[i].second];
    int q = query(temp);
    ans = max(ans, q + 1);
    temp = mp[arr[i].first + arr[i].second];
    update(temp, q + 1);
  }
  printf("%d\n", ans);
  return 0;
}
