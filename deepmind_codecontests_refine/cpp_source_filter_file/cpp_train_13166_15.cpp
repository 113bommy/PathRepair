#include <bits/stdc++.h>
using namespace std;
vector<long long> store[26];
int val[26];
int main() {
  long long sum = 0;
  for (int i = 0; i < 26; i++) cin >> val[i];
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    sum = sum + val[str[i] - 'a'];
    store[str[i] - 'a'].push_back(sum);
  }
  long long ans = 0;
  for (int i = 0; i < 26; i++) {
    vector<long long> &a = store[i];
    map<long long, int> ahaa;
    for (int idx = 0; idx < a.size(); idx++) {
      if (ahaa.count(a[idx] - val[i])) ans += ahaa[a[idx - val[i]]];
      ahaa[a[idx]]++;
    }
  }
  cout << ans << endl;
  return 0;
}
