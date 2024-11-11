#include <bits/stdc++.h>
using namespace std;
const int SIZE = 123456;
const int ALPHA = 26;
vector<int> value;
string word;
int n;
long long solve(int c) {
  int v = value[c];
  unordered_map<long long, long long> mp;
  long long cnt = 0;
  long long sum = 0;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    if (word[i] - 'a' == c) {
      if (cnt == 0) {
        sum = 0;
        mp[0] = 1;
      } else {
        long long s = sum + v * (cnt - 1);
        res += mp[s];
        mp[s + v]++;
      }
      cnt++;
    } else {
      sum += value[word[i] - 'a'];
    }
  }
  return res;
}
int main() {
  int a;
  long long ans = 0;
  for (int i = 0; i < ALPHA; i++) {
    cin >> a;
    value.push_back(a);
  }
  cin >> word;
  n = word.size();
  for (int i = 0; i < ALPHA; i++) {
    ans += solve(i);
  }
  cout << ans << endl;
  return 0;
}
