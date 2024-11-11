#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v1, v2;
    for (i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      v1.push_back(temp);
    }
    for (i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      v2.push_back(temp);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (i = 0; i < n; i++) {
      cout << v1[i] << " ";
    }
    cout << '\n';
    for (i = 0; i < n; i++) {
      cout << v2[n - i - 1] << " ";
    }
    cout << '\n';
  }
}
