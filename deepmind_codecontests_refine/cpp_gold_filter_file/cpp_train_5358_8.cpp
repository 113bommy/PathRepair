#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b;
  cin >> a >> b;
  int count = 1;
  count += (a + b);
  if (a == 0) {
    for (int i = count; i >= 1; i--) cout << i << " ";
  } else if (b == 0)
    for (int i = 1; i <= count; i++) cout << i << " ";
  else {
    cout << 1 << " ";
    for (int i = count - a + 1; i <= count; i++) cout << i << " ";
    for (int i = count - a; i > 1; i--) cout << i << " ";
  }
  return 0;
}
