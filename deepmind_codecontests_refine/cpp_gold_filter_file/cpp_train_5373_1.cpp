#include <bits/stdc++.h>
using namespace std;
int k, cnt, cnt1, ans = 0x3f3f;
vector<char> vec;
string s;
int main() {
  cin >> s >> k;
  if (s.length() < k)
    cout << "impossible";
  else {
    for (int i = 0; i < s.length(); i++) vec.push_back(s[i]);
    sort(vec.begin(), vec.end());
    for (int i = 1; i <= vec.size(); i++) {
      if (vec[i] ^ vec[i - 1]) cnt++;
      if (cnt >= k) break;
    }
    cout << k - cnt;
  }
}
