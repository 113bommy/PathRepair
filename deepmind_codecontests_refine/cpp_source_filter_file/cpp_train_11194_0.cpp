#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (n > a * b) {
    puts("-1");
    return 0;
  }
  int cur = 1;
  for (int i = 0; i < a; i++) {
    vector<int> v;
    for (int j = 0; j < b; j++) {
      if (cur <= n)
        v.push_back(cur++);
      else
        v.push_back(0);
    }
    if (a % 2 == 0 and i % 2 == 1) reverse(v.begin(), v.end());
    cout << v[0];
    for (int j = 1; j < a; j++) {
      cout << ' ' << v[j];
    }
    cout << endl;
  }
}
