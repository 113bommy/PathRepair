#include <bits/stdc++.h>
using namespace std;
int ar2[1000000];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 0;
  cin >> t;
  while (t--) {
    int n = 0, k = 0, d = 0, ct = 0, mct = 10000000;
    cin >> n >> k >> d;
    int arr[n];
    for (int a = 0; a < n; a++) cin >> arr[a];
    memset(ar2, 0, sizeof(ar2));
    for (int a = 0; a < n; a++) {
      if (ar2[arr[a]] == 0) ct++;
      ar2[arr[a]]++;
      if (a >= d) {
        ar2[arr[a - d]]--;
        if (ar2[arr[a - d]] == 0) ct--;
      }
      a >= d - 1 ? mct = min(mct, ct) : mct = mct;
    }
    cout << mct << "\n";
  }
}
