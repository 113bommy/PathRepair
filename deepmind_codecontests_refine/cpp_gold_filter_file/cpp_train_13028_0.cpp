#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1)
      cnt1++;
    else
      cnt2++;
  }
  if (cnt2 >= 1) {
    cnt2--;
    cout << 2 << " ";
  }
  if (cnt1 >= 1) {
    cnt1--;
    cout << 1 << " ";
  }
  long long sum = 0;
  for (int i = 0; i < cnt2; i++) {
    cout << 2 << " ";
  }
  for (int i = 0; i < cnt1; i++) {
    cout << 1 << " ";
  }
}
