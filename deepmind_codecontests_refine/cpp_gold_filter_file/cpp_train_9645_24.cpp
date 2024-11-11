#include <bits/stdc++.h>
using namespace std;
int n;
bool b[605];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b[x] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= 600; i++) {
    if (b[i]) {
      ans++;
    }
  }
  cout << ans << endl;
}
