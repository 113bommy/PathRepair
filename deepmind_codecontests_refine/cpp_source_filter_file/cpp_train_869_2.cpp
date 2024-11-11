#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  double d;
  cin >> n;
  vector<int> v, ans;
  while (n--) {
    cin >> a >> d;
    v.push_back(a);
  }
  int m = -1;
  for (int i = 0; i < v.size(); i++) {
    int k = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (v[j] < v[i] && ans[j] > k) k = ans[j];
    }
    ans.push_back(k + 1);
    m = max(m, k + 1);
  }
  cout << v.size() - m << endl;
  return 0;
}
