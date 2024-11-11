#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, sum = 0, b;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> a;
      sum += a;
    }
    v.push_back(sum);
    sum = 0;
  }
  b = v[0];
  sort(v.begin(), v.end());
  vector<int>::iterator it;
  it = find(v.begin(), v.end(), b);
  cout << distance(v.begin(), it) << endl;
}
