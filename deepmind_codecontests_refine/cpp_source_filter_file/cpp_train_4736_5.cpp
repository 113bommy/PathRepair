#include <bits/stdc++.h>
using namespace std;
int n, k, c;
int main() {
  while (cin >> n >> k >> c) {
    vector<int> v(c);
    for (int i = 0; i < (c); i++) cin >> v[i];
    int sum = 0;
    if (c != 0) sum = (v[0] - 1) / k + (n - v[c - 1]) / k;
    for (int i = 0; i + 1 < c; ++i) sum += (v[i + 1] - v[i] - 1) / k;
    cout << sum + c << endl;
  }
}
