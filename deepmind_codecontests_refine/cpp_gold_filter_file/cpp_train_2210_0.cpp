#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int a[100100];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], mp[a[i]]++;
  long long Ans = 0;
  for (int i = 0; i < n; i++) {
    mp[a[i]]--;
    Ans += mp[a[i] * -1];
  }
  cout << Ans;
  return 0;
}
