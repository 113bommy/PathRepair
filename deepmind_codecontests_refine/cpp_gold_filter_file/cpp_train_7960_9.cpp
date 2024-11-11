#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
const long long LLINF = numeric_limits<long long>::max();
const unsigned long long ULLINF = numeric_limits<unsigned long long>::max();
string s[] = {"", "", "2", "3", "322", "5", "35", "7", "7222", "7332"};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string a;
  cin >> a;
  string x = "";
  for (char f : a) x += s[f - '0'];
  sort((x).begin(), (x).end());
  reverse((x).begin(), (x).end());
  cout << x;
  return 0;
}
