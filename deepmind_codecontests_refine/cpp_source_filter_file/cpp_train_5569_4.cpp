#include <bits/stdc++.h>
using namespace std;
long long n, k;
queue<int> ans;
int a[200];
void init() {
  a[0] = 1;
  a[1] = 1;
  a[2] = 2;
  for (int i = 3; i <= n; i++) a[i] = a[i - 1] + a[i - 2];
}
int main() {
  cin >> n >> k;
  init();
  for (int i = 1; i <= n;) {
    if (k <= a[n - i]) {
      ans.push(i);
      i++;
      continue;
    }
    ans.push(i + 1);
    ans.push(i);
    k -= a[n - i];
    i += 2;
  }
  while (!ans.empty()) {
    if (ans.size() == 1)
      cout << ans.front() << endl;
    else
      cout << ans.front() << " ";
    ans.pop();
  }
  return 0;
}
