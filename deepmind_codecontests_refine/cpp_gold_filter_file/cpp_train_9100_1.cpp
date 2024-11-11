#include <bits/stdc++.h>
using namespace std;
void sieveOfEratosthenes(int n, bool prime[]) {
  int i, p;
  for (i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (p = i * i; p <= n; p += i) prime[p] = false;
    }
  }
}
unsigned long long int power(int n, int p) {
  unsigned long long int m = 1;
  while (p > 0) {
    m *= n;
    p--;
  }
  return m;
}
char median(vector<char> &str) {
  int n = str.size(), index;
  index = (n - 1) / 2;
  char s = str[index];
  str.erase(str.begin() + index);
  return s;
}
vector<char> encode(vector<char> &str) {
  int i;
  vector<char> res;
  while (str.size() > 0) res.push_back(median(str));
  return res;
}
void result(vector<char> str) {
  int i;
  vector<char> decoded;
  decoded = encode(str);
  for (i = 0; i < decoded.size(); ++i) cout << decoded[i];
  decoded = encode(decoded);
  cout << "\n";
  for (i = 0; i < decoded.size(); ++i) cout << decoded[i];
  decoded = encode(decoded);
  cout << "\n";
  for (i = 0; i < decoded.size(); ++i) cout << decoded[i];
}
int count(int n, int sum, int mx) { return ceil((float)sum / mx); }
int main() {
  int t, e, m, n, k, mn = INT_MAX, j, i, mx = INT_MIN, a, b, sum = 0;
  string s;
  cin >> n >> mx;
  int cards[n];
  pair<int, int> days[n];
  for (i = 0; i < n; i++) {
    cin >> cards[i];
    sum += cards[i];
  }
  cout << count(n, abs(sum), mx);
  return 0;
}
