#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
bool one(string s) {
  long long i;
  for (i = 0; i < s.size(); i++) {
    if (abs(s[i + 1] - s[i]) == 1) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie();
  long long n;
  cin >> n;
  string s;
  while (n--) {
    string s1, s2;
    s1 = "", s2 = "";
    cin >> s;
    long long i;
    for (i = 0; i < s.size(); i++) {
      if (s[i] % 2 == 0)
        s1 += s[i];
      else
        s2 += s[i];
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (one(s1 + s2))
      cout << s1 + s2 << "\n";
    else if (one(s2 + s1))
      cout << s2 + s1 << "\n";
    else
      cout << "No answer"
           << "\n";
  }
}
