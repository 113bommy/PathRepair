#include <bits/stdc++.h>
using namespace std;
string str;
int countA[6000];
void input() { cin >> str; }
void solve() {
  vector<pair<int, char> > freq;
  for (int i = 0; i < str.length();) {
    int j = i + 1;
    while (j < str.length() && str[j] == str[i]) j++;
    freq.push_back({j - i, str[i]});
    i = j;
  }
  for (int i = (int)freq.size() - 1; i >= 0; i--)
    if (freq[i].second == 'a')
      countA[i] = freq[i].first + countA[i + 1];
    else
      countA[i] = countA[i + 1];
  int ans = countA[0];
  int preB = 0;
  int preA = 0;
  for (int i = 0; i < freq.size(); i++) {
    if (freq[i].second == 'b') {
      preB += freq[i].first;
      ans = max(ans, preB + countA[i]);
    } else {
      int countB = 0;
      preA += freq[i].first;
      for (int j = i + 1; j < freq.size(); j++) {
        if (freq[j].second == 'b') {
          countB += freq[j].first;
          ans = max(ans, countB + preA + countA[j]);
        }
      }
    }
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  input();
  solve();
  return 0;
}
