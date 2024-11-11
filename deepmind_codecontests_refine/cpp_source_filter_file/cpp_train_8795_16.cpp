#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i > 0) {
      v.push_back(arr[i]);
    }
  }
  int N;
  if (!v.empty()) {
    N = v.size();
    sort(v.begin(), v.end());
    int ans = 0;
    while (v[N - 1] >= arr[0]) {
      v[N - 1]--;
      arr[0]++;
      ans++;
      sort(v.begin(), v.end());
    }
    cout << max(ans, 1);
  } else {
    cout << 0;
  }
  return 0;
}
