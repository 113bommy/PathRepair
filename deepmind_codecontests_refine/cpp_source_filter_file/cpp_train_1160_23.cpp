#include <bits/stdc++.h>
using namespace std;
int N, arr[100001];
long long ans = 0;
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  for (int i = 1; i <= N; i++) ans += (N - arr[i] + 1) * arr[i];
  for (int i = 1; i < N; i++)
    ans -= (N - max(arr[i], arr[i + 1]) + 1) * min(arr[i], arr[i + 1]);
  cout << ans << '\n';
  return 0;
}
