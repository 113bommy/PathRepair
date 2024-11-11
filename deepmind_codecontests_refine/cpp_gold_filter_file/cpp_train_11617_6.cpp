#include <bits/stdc++.h>
using namespace std;
int n, a[100000], k;
bool b[100005];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  k = n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    b[a[i]] = true;
    while (b[k]) {
      cout << k << " ";
      k--;
    }
    cout << endl;
  }
}
