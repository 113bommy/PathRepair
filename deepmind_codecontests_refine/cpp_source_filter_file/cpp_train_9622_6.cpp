#include <bits/stdc++.h>
using namespace std;
int n, a[1000], b[1000], dem;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] == dem + 1) {
      dem++;
      b[dem] = i;
    }
  }
  if (dem == 0) {
    cout << "NO";
    return 0;
  } else
    cout << dem << endl;
  for (int i = 1; i <= dem; ++i) cout << b[i] + 2000 << " ";
  return 0;
}
