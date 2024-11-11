#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, k, tot = 0, cnt = 0;
  int a = 0, b = 0, c = 0;
  string s;
  cin >> n >> m >> k;
  int arr[n], brr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    brr[i] = arr[i];
  }
  sort(brr, brr + n);
  int i = n - m * k;
  for (; i < n; i++) {
    tot += brr[i];
  }
  vector<int> v;
  a = brr[n - m * k];
  i = n - m * k;
  c = 1;
  for (; i < n - 1; i++) {
    if (brr[i] == brr[i + 1])
      c++;
    else
      break;
  }
  b = m;
  for (i = 0; i < n; i++) {
    if (arr[i] > a)
      b--;
    else if (arr[i] == a) {
      if (c == 0)
        continue;
      else {
        c--;
        b--;
      }
    }
    if (b == 0) {
      v.push_back(i + 1);
      b = m;
      k--;
    }
    if (k == 1) break;
  }
  cout << tot << endl;
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long q(1);
  while (q--) {
    solve();
  }
  return 0;
}
