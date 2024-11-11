#include <bits/stdc++.h>
using namespace std;
int a[100005];
map<long long, long long> m;
string s;
map<string, long long> x;
string h(long long n) {
  string t = "";
  while (n) {
    if ((n % 10) % 2 == 0)
      t += "0";
    else
      t += "1";
    n /= 10;
  }
  while (t.length() < 20) t += "0";
  reverse(t.begin(), t.end());
  return t;
}
int main() {
  long long int n, i, k;
  char c;
  string temp;
  cin >> n;
  while (n--) {
    cin >> c;
    if (c == '+') {
      cin >> k;
      m[k]++;
      x[h(k)]++;
    } else if (c == '-') {
      cin >> k;
      m[k]--;
      x[h(k)]--;
    } else {
      cin >> s;
      temp = "";
      if (s.size() < 20) {
        for (i = 0; i < 20 - s.size(); i++) temp += "0";
        temp += s;
      }
      cout << x[h(k)] << endl;
    }
  }
  return 0;
}
