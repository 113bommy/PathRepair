#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000001;
int a[maxn];
const int mod = 1e9 + 7;
const int inf = 1e9;
char L[200], R[200];
map<int, int> m;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
string getnum(string code) {
  int res = 0;
  int d = 1;
  for (int i = (int)code.length() - 1; i >= 0; i--) {
    res += d * (code[i] - 'A' + 1);
    d *= 26;
  }
  return to_string(res);
}
string ones[] = {"zero",    "one",     "two",       "three",    "four",
                 "five",    "six",     "seven",     "eight",    "nine",
                 "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                 "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string tens[]{"twenty", "thirty",  "forty",  "fifty",
              "sixty",  "seventy", "eighty", "ninety"};
long long d[2][111][111];
bool ispalindrome(string s) {
  int n = s.length();
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1]) return false;
  }
  return true;
}
int was[maxn];
vector<int> ans[maxn];
vector<pair<int, int> > v;
void printq(int x) { cout << '?' << ' ' << x << endl; }
void printans(int x) { cout << '!' << ' ' << x << endl; }
int main() {
  int a, b;
  char ch;
  int c, d;
  cin >> a >> ch >> b;
  cin >> c >> ch >> d;
  int s = a * 60 + b;
  int t = c * 60 + d;
  int p = ((s - t) + 24 * 60) % 24 * 60;
  cout << (p / 60 < 10 ? "0" : "") << p / 60 << ':' << (p % 60 < 10 ? "0" : "")
       << p % 60 << endl;
}
