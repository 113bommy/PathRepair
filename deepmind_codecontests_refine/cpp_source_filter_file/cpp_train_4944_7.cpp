#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k1, k2;
  vector<int> s1;
  vector<int> s2;
  cin >> k1;
  for (int i = 0; i < k1; i++) {
    int val;
    cin >> val;
    s1.push_back(val);
  }
  cin >> k2;
  for (int i = 0; i < k2; i++) {
    int val;
    cin >> val;
    s2.push_back(val);
  }
  int i = 0;
  while (k1 > 0 && k2 > 0 && i <= (n) * (n - 1)) {
    if (s1[i] > s2[i]) {
      s1.push_back(s2[i]);
      s1.push_back(s1[i]);
      k1++;
      k2--;
    } else {
      s2.push_back(s1[i]);
      s2.push_back(s2[i]);
      k1--;
      k2++;
    }
    i++;
  }
  if (i > (n) * (n - 1)) {
    cout << -1;
    return 0;
  }
  if (k1 == 0) {
    cout << i << " " << 2;
  } else
    cout << i << " " << 1;
}
