#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
const int mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  unordered_map<int, string> m;
  m[0] = "zero";
  m[1] = "one";
  m[2] = "two";
  m[3] = "three";
  m[4] = "four";
  m[5] = "five";
  m[6] = "six";
  m[7] = "seven";
  m[8] = "eight";
  m[9] = "nine";
  m[10] = "ten";
  m[11] = "eleven";
  m[12] = "twelve";
  m[13] = "thirteen";
  m[14] = "fourteen";
  m[15] = "fifteen";
  m[16] = "sixteen";
  m[17] = "seventeen";
  m[18] = "eighteen";
  m[19] = "nineteen";
  m[20] = "twenty";
  m[30] = "thirty";
  m[40] = "forty";
  m[50] = "fifty";
  m[60] = "sixty";
  m[70] = "seventy";
  m[80] = "eighty";
  m[90] = "ninety";
  if (m.find(n) != m.end())
    cout << m[n];
  else
    cout << m[n / 10 * 10] << '-' << m[n % 10];
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
