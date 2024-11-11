#include <bits/stdc++.h>
using ::std::cin;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::std::unordered_map;
int main() {
  ::std::ios_base::sync_with_stdio(false);
  unordered_map<char, int> numbers;
  for (char c = '0'; c <= '9'; ++c) numbers[c] = c - '0';
  for (char c = 'A'; c <= 'Z'; ++c) numbers[c] = c - 'A' + 10;
  for (char c = 'a'; c <= 'z'; ++c) numbers[c] = c - 'a' + 36;
  numbers['-'] = 62;
  numbers['_'] = 63;
  const int MOD = 1e9 + 7;
  unordered_map<char, int> ways;
  for (auto charAndNumber : numbers) {
    ways[charAndNumber.first] = 1;
    for (int i = 0; i < 6 - __builtin_popcount(charAndNumber.second); ++i)
      ways[charAndNumber.first] = 3LL * ways[charAndNumber.first] % MOD;
  }
  string s;
  cin >> s;
  int result = 1;
  for (char c : s) result = 1LL * result * ways[c] % MOD;
  cout << result << endl;
  return 0;
}
