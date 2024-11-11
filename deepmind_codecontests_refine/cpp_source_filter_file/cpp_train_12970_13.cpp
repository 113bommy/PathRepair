#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (b / gcd(a, b)) * a; }
void print() {}
void pLine() { cout << endl; }
template <typename T, typename... arg>
void print(T x, arg... ar) {
  cout << x;
  print(ar...);
}
const double PI = acos(-1);
const double eps = numeric_limits<double>::epsilon();
void rem(string &str) {
  while (str[0] == '0' and (str).size() - 1) str.erase(0, 1);
}
void sol() {
  string x, ans = "";
  cin >> x;
  int sum;
  vector<int> dp[3];
  for (int i = (int)0; i < (int)(x).size(); i++) {
    int temp = x[i] - '0';
    sum = (sum + temp) % 3;
    dp[temp % 3].push_back(i);
  }
  if (!sum) return print(x, '\n');
  if (sum == 2) swap(dp[1], dp[2]);
  if ((dp[1]).size() >= 1) {
    string temp = x;
    temp.erase(temp.begin() + dp[1].back());
    rem(temp);
    if (temp.size() > ans.size()) ans = temp;
  }
  if ((dp[2]).size() >= 2) {
    string temp = x;
    temp.erase(temp.begin() + dp[2].back());
    temp.erase(temp.begin() + dp[2][(dp[2]).size() - 2]);
    rem(temp);
    if (temp.size() > ans.size()) ans = temp;
  }
  if (ans.size() == 0) return print(-1);
  print(ans);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sol();
  return 0;
}
