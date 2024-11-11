#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
priority_queue<int> s;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    x -= i;
    s.push(x);
    if (s.top() > x) {
      ans += s.top() - x;
      s.pop();
      s.push(x);
    }
  }
  cout << ans << endl;
}
