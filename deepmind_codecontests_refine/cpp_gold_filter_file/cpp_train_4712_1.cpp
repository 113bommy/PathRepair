#include <bits/stdc++.h>
using namespace std;
vector<int> gV(int n) {
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  return v;
}
int* gA(int n) {
  int* arr = new int[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  return arr;
}
void solve() {
  long long int n, x, ans = 0;
  cin >> n >> x;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int idx = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] >= x) {
      ans++;
    } else {
      idx = i;
      break;
    }
  }
  for (int i = idx; i >= 0; i--) {
    int total;
    if (idx < 0) break;
    if (x % arr[i] == 0) {
      total = x / arr[i];
    } else {
      total = x / arr[i] + 1;
    }
    if (idx - (total - 1) >= 0) {
      if (idx - i + 1 >= total) {
        ans++;
        i -= (total - 1);
        idx -= (total);
      } else {
        if ((i - (total - 1) >= 0) && (arr[i - (total - 1)] * total >= x)) {
          ans++;
          i -= (total - 1);
          idx -= (total);
        }
      }
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  };
  return 0;
}
