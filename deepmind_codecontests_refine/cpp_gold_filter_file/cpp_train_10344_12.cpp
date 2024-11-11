#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, front = 0, back = 0;
  cin >> n;
  int arr[n];
  map<long long int, long long int> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    m[arr[i]] = i;
  }
  long long int q;
  cin >> q;
  while (q--) {
    long long int x;
    cin >> x;
    front += m[x] + 1;
    back += (n - m[x]);
  }
  cout << front << " " << back << endl;
}
