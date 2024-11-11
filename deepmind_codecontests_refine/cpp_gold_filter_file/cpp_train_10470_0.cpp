#include <bits/stdc++.h>
using namespace std;
int n, ans;
set<int> S;
int main() {
  cin >> n;
  for (int i = 1, a; i <= n; i++) {
    cin >> a;
    if (a == i)
      ans++;
    else
      S.insert(a);
  }
  cout << int(ans + (int)S.size() / 2) << endl;
  return 0;
}
