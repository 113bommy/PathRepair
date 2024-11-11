#include <bits/stdc++.h>
using namespace std;
void print(const vector<int>& freq) {
  string s;
  string mid = "";
  for (int i = 0; i != freq.size(); ++i) {
    s += string(freq[i] / 2, 'a' + i);
    if (freq[i] & 1) mid = string(1, 'a' + i);
  }
  cout << s;
  cout << mid;
  reverse(s.begin(), s.end());
  cout << s << endl;
}
void modify(vector<int>& freq, const vector<int>& odds) {
  int n = odds.size();
  for (int i = 0; 2 * (i + 1) <= n; ++i) {
    ++freq[odds[i]];
    --freq[odds[n - i - 1]];
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  vector<int> freq(26, 0);
  for (char c : S) ++freq[c - 'a'];
  vector<int> odds;
  for (int i = 1; i != freq.size(); ++i) {
    if (freq[i] & 1) odds.push_back(i);
  }
  if (odds.size() < 2) {
    print(freq);
  } else {
    modify(freq, odds);
    print(freq);
  }
  return 0;
}
