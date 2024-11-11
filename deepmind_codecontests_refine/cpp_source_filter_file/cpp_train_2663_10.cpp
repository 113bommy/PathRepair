#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
int N;
string s;
int occ[26];
long long ways[1001];
int longest_sub[1000];
int minimum_num[1000];
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int main() {
  cin >> N;
  cin >> s;
  for (int i = 0; i < 26; i++) cin >> occ[i];
  for (int i = 0; i < N; i++) ways[i] = 0;
  ways[N] = 1L;
  longest_sub[N] = 0;
  minimum_num[N] = 0;
  for (int pos = N - 1; pos >= 0; pos--) {
    minimum_num[pos] = 100000;
    for (int i = 0; i < occ[s[pos] - 'a']; i++) {
      if (pos + i >= N) break;
      bool valid = true;
      for (int j = 0; j <= i; j++) {
        if (i >= occ[s[pos + j] - 'a']) {
          valid = false;
          break;
        }
      }
      if (!valid) break;
      ways[pos] = (ways[pos] + ways[pos + i + 1]) % MOD;
      longest_sub[pos] = max(i + 1, longest_sub[pos + 1]);
      minimum_num[pos] = min(minimum_num[pos], 1 + minimum_num[pos + i + 1]);
    }
  }
  cout << ways[0] << endl;
  cout << longest_sub[0] << endl;
  cout << minimum_num[0] << endl;
  return 0;
}
