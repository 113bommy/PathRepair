#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    int cnt = 1;
    for (int j = 1; j < n; j++) {
      if (a[i] < a[j]) cnt++;
    }
    cout << cnt << " ";
  }
}
