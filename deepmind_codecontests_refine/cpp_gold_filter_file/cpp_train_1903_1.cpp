#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> sign(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> sign[i];
    }
    vector<int> ex;
    for (int i = 0; i < n; i++) {
      if (sign[i] == 0) ex.push_back(v[i]);
    }
    sort(ex.rbegin(), ex.rend());
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (sign[i] == 1)
        cout << v[i] << " ";
      else {
        cout << ex[j] << " ";
        j++;
      }
    }
    cout << endl;
  }
}
