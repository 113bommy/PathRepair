#include <bits/stdc++.h>
using namespace std;
int main() {
  int counter[10];
  memset(counter, 0, sizeof counter);
  string t;
  cin >> t;
  for (int i = 0; i < t.size(); i++) {
    t[i] -= '0';
    counter[t[i]]++;
  }
  string s;
  cin >> s;
  counter[2] += counter[5];
  counter[5] = 0;
  counter[6] += counter[9];
  counter[9] = 0;
  int cnt[10];
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < s.length(); i++) {
    s[i] -= '0';
    cnt[s[i]]++;
  }
  cnt[2] += cnt[5];
  cnt[6] += cnt[9];
  cnt[9] = 0;
  cnt[5] = 0;
  int ans = 400000;
  set<int> st;
  for (int i = 1; i < 10; i++) {
    if (counter[i]) {
      st.insert(cnt[i] / counter[i]);
    }
  }
  cout << *st.begin();
  return 0;
}
