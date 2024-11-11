#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t;
  cin >> t;
  for (; t > 0; t--) {
    int n;
    cin >> n;
    vector<long> vec;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      i != 0 ? vec.push_back(a + vec.at(i - 1)) : vec.push_back(a);
    }
    int k = n - 1;
    int m1 = 0, m2 = 0;
    for (int i = 1; i < n; i++) {
      if (vec.at(i) < vec.at(m1)) m1 = i;
      if (vec.at(i) > vec.at(m2)) m2 = i;
    }
    if (m2 != k && (vec.at(m2) >= vec.at(k))) {
      cout << "NO" << endl;
    } else {
      if ((vec.at(m2) - vec.at(m1)) >= vec.at(k))
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
  }
  return 0;
}
