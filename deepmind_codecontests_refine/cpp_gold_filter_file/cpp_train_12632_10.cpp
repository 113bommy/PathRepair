#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, M = 2 * N;
const int MAX_X = 2001;
const int MAX_N = 5003;
string addbig(string n1, string n2) {
  string res;
  int p1 = 0, p2 = 0;
  int rem = 0;
  while (p1 < n1.size() or p2 < n2.size()) {
    int sum = rem;
    if (p1 < n1.size()) sum += n1[p1] - '0';
    if (p2 < n2.size()) sum += n2[p2] - '0';
    int r = sum % 10;
    rem = sum / 10;
    res.push_back(r + '0');
    p1++;
    p2++;
  }
  if (rem > 0) res.push_back(rem + '0');
  return res;
}
string mul(string n) {
  string res;
  int rem = 0;
  for (char d : n) {
    int sum = (d - '0') * 2 + rem;
    rem = sum / 10;
    sum %= 10;
    res.push_back(sum + '0');
  }
  if (rem > 0) res.push_back(rem + '0');
  return res;
}
vector<string> power(MAX_X);
string maxbig(string n1, string n2) {
  if (n1.size() > n2.size()) return n1;
  if (n2.size() > n1.size()) return n2;
  reverse(n1.begin(), n1.end());
  reverse(n2.begin(), n2.end());
  if (n1 < n2) n1 = n2;
  reverse(n1.begin(), n1.end());
  return n1;
}
vector<int> T(MAX_N), P(MAX_N), done(MAX_N);
map<int, int> sell;
int n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  power[0] = "1";
  for (int i = 1; i < MAX_X; ++i) power[i] = mul(power[i - 1]);
  cin >> n;
  set<int> st;
  for (int i = 0; i < n; ++i) {
    string t;
    int p;
    cin >> t >> p;
    if (t == "win") T[i] = 0, P[i] = p;
    if (t == "sell") T[i] = 1, P[i] = p, sell[p] = i;
  }
  string res = "0";
  for (auto it = sell.rbegin(); it != sell.rend(); ++it) {
    int idx = it->second;
    int tar = it->first;
    for (int i = idx - 1; i >= 0 and !done[i]; --i) {
      if (!T[i] and P[i] == tar) {
        res = addbig(res, power[tar]);
        for (int j = i; j <= idx; ++j) done[j] = 1;
        break;
      }
    }
  }
  reverse(res.begin(), res.end());
  cout << res << '\n';
  return 0;
}
