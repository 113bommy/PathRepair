#include <bits/stdc++.h>
using namespace std;
pair<int, long long> arr[300010];
int main(void) {
  int N;
  cin >> N;
  long long sum = 0;
  long long ans = 0;
  for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
  for (int i = 0; i < N; i++) sum += arr[i].first;
  if (sum > 0) {
    for (int i = 0; i < N; i++) arr[i].first = -arr[i].first;
  }
  for (int i = 0; i < 64; i++) {
    sum = 0;
    for (int j = 0; j < N; j++) {
      if (arr[j].second == (1LL << i)) sum += arr[j].first;
    }
    if (sum < 0) ans += (1LL << i);
    for (int j = 0; j < N; j++) {
      if (arr[j].second & (1LL << i)) {
        arr[j].second &= ~(1LL << i);
        if (sum < 0) arr[j].first = -arr[j].first;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
