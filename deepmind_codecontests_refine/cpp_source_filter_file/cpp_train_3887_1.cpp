#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, mine = 0, bro, count = 0;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
    bro += a;
  }
  sort(v.begin(), v.end(), greater<int>());
  for (int j = 0; j < n; j++) {
    mine += v[j];
    bro -= v[j];
    count++;
    if (mine > bro) break;
  }
  cout << count << endl;
  return 0;
}
