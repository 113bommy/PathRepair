#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  map<char, int> base;
  char ch;
  ch = '0';
  for (long long int i = 0; i < 10; i++) {
    base[ch] = i;
    ch++;
  }
  ch = 'A';
  for (long long int i = 10; i < 36; i++) {
    base[ch] = i;
    ch++;
  }
  ch = 'a';
  for (long long int i = 36; i < 62; i++) {
    base[ch] = i;
    ch++;
  }
  ch = '-';
  base[ch] = 62;
  ch = '_';
  base[ch] = 63;
  long long int ways[64];
  long long int rem, store;
  for (long long int i = 0; i < 64; i++) {
    long long int temp = 1;
    store = i;
    for (long long int j = 1; j <= 6; j++) {
      rem = store % 2;
      store = store / 2;
      if (rem == 0) {
        temp = temp * 3;
      }
    }
    ways[i] = temp;
  }
  long long int ans = 1, len, val;
  string str;
  cin >> str;
  len = str.size();
  for (long long int i = 0; i < len; i++) {
    val = ways[base[str[i]]];
    ans = (ans * val) % 1000000007;
  }
  cout << ans;
  return 0;
}
