#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  int i, j, l;
  for (i = 2; i <= n; i++) cin >> a[i];
  stack<int> s;
  a[1] = 0;
  j = n;
  while (j > 0) {
    s.push(j);
    j = a[j];
  }
  while (!s.empty()) {
    j = s.top();
    s.pop();
    cout << j << " ";
  }
  cout << endl;
  return 0;
}
