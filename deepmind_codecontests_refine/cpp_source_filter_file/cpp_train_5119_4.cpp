#include <bits/stdc++.h>
using namespace std;
int main() {
  int n{0}, m{0};
  cin >> n >> m;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  vector<int> sum(n);
  sum[0] = vec[0];
  for (int i = 1; i < n; i++) {
    sum[i] = vec[i] + sum[i - 1];
  }
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      cout << "0 ";
      v.push_back(vec[i]);
    } else {
      if (m - sum[i] >= 0) {
        cout << "0 ";
      } else {
        sort(v.begin(), v.end());
        int z = v.size(), sm = 0, count = 0;
        for (int l = z - 1; l >= 0; l--) {
          sm += vec[l];
          count++;
          if (m - sum[i] + sm >= 0) {
            break;
          }
        }
        cout << count << " ";
      }
      v.push_back(vec[i]);
    }
  }
  return 0;
}
