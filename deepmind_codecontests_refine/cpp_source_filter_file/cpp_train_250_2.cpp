#include <bits/stdc++.h>
using namespace std;
int data[207], n, k, ans = -INT_MAX;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> data[i];
  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ++r) {
      vector<int> in, out;
      for (int i = l; i <= r; ++i) in.push_back(data[i]);
      for (int j = 0; j < l; ++j) out.push_back(data[j]);
      for (int j = r + 1; j < n; ++j) out.push_back(data[j]);
      sort(in.begin(), in.end());
      sort(out.begin(), out.end());
      for (size_t i = 0; i <= k && i < in.size() && i < out.size() &&
                         in[i] < out[out.size() - i - 1];
           ++i)
        swap(in[i], out[out.size() - i - 1]);
      int sum = 0;
      for (size_t i = 0; i < in.size(); ++i) sum += in[i];
      ans = max(ans, sum);
      if (ans == 0) cout << l << ' ' << r << '\n';
    }
  }
  cout << ans << '\n';
  return 0;
}
