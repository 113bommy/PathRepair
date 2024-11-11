#include <iostream>
using namespace std;
int main() {
  int n, x, ans = 1, at;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    at += l;
    if (at <= x) ans++;
  }
  cout << ans << endl;
}
