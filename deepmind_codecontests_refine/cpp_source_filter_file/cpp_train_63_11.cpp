#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int s = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (!(k % a)) s = max(k / a, s);
  }
  cout << s << endl;
  return 0;
}
