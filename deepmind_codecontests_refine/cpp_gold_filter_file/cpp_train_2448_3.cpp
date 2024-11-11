#include <bits/stdc++.h>
using namespace std;
map<char, int> mp;
int main() {
  string a, b;
  cin >> a;
  cin >> b;
  for (int i = a.size() - 1; i < b.size(); i++) {
    mp[b[i]]++;
  }
  long long cnt = 0;
  int lst = b.size() - 1;
  for (int i = a.size() - 1; i >= 0; i--) {
    if (i != a.size() - 1) {
      mp[b[lst]]--;
      mp[b[i]]++;
      lst--;
    }
    if (a[i] == '1') {
      cnt += mp['0'];
    } else {
      cnt += mp['1'];
    }
  }
  cout << cnt << endl;
}
