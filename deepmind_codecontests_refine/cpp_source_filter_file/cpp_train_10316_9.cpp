#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int cnt = 0;
  for (int i = 0; i < n / 2; i++) {
    map<char, int> mp;
    mp[a[i]]++;
    mp[a[n - i - 1]]++;
    mp[b[i]]++;
    mp[b[n - i - 1]]++;
    if (mp.size() == 4) {
      cnt += 2;
    } else if (mp.size() == 2) {
      if (mp[a[i]] != 2) {
        cnt++;
      }
    } else if (mp.size() == 3) {
      if (mp[a[i]] == mp[a[n - i - 1]]) {
        cnt += 2;
      } else {
        cnt++;
      }
    }
  }
  if (n % 2 == 1 && a[n / 2] != b[n / 2]) {
    cnt++;
  }
  cout << cnt << "\n";
}
