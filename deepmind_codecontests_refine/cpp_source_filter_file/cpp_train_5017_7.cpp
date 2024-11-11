#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, cnt = 0, mx = -1;
  cin >> n;
  long long enter[n + 1], exit[n + 1], arr[n + 1];
  for (long long i = 1; i <= n; i++) {
    cin >> arr[i];
    enter[arr[i]] = i;
  }
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    exit[x] = i;
  }
  for (long long i = 1; i <= n; i++) {
    if (enter[arr[i]] > exit[arr[i]]) {
      cnt++;
    } else if (enter[arr[i]] <= exit[arr[i]]) {
      if (mx > enter[arr[i]]) {
        cnt++;
      }
      mx = max(mx, exit[arr[i]]);
    }
  }
  cout << cnt;
}
