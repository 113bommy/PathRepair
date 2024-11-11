#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  while (cin >> n) {
    long long arr[n], mx = -1;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      mx = max(mx, arr[i]);
    }
    long long ans = 1, c = 0;
    vector<long long> vec;
    for (int i = 0; i < n; i++) {
      if (mx == arr[i]) {
        vec.push_back(i);
      }
    }
    if (vec.size() == 1) {
      cout << 1 << endl;
      continue;
    }
    for (int i = 0; i < vec.size() - 1; i++) {
      if (vec[i + 1] - vec[i] == 1) {
        if (c == 0)
          c += 2;
        else
          c++;
      } else
        c = 0;
      ans = max(ans, c);
    }
    cout << ans << endl;
  }
  return 0;
}
