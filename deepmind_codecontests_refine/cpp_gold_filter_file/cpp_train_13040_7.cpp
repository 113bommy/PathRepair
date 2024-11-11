#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      a.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      b.push_back(temp);
    }
    int mna = *min_element(a.begin(), a.end());
    int mnb = *min_element(b.begin(), b.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) ans += max(a[i] - mna, b[i] - mnb);
    cout << ans << endl;
  }
  return 0;
}
