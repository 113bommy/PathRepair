#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    vector<int> vec;
    int x = 0;
    int p = 0;
    int g;
    for (int j = 0; j < b; j++) {
      cin >> g;
      vec.push_back(g - p - 1);
      p = g;
    }
    vec.push_back(a - g);
    for (int j = 1; j < b; ++j) vec[j] = (vec[j] + 1) / 2;
    for (int i = 0; i < vec.size(); i++) x = max(x, vec[i]);
    cout << x + 1 << endl;
  }
}
