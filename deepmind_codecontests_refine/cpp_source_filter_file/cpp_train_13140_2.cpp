#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
  }
}
