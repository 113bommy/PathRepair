#include <bits/stdc++.h>
using namespace std;
long long int ipow(long long int x, long long int n) {
  long long int result = 1;
  while (n) {
    if (n & 1) result = result * x;
    n = n / 2;
    x = x * x;
  }
  return result;
}
bool issubstr(string s, string t) {
  if (s.find(t) != -1) return true;
  return false;
}
bool ispermutation(string s, string t) {
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  if (s == t) return true;
  return false;
}
bool issubseq(string s, string t) {
  int count = 0;
  int prev = -1;
  for (int i = 0; i < t.size(); i++) {
    for (int j = prev + 1; j < s.size(); j++) {
      if (t[i] == s[j]) {
        count++;
        prev = j;
        break;
      }
    }
  }
  if (count == t.size()) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b;
  cin >> a >> b;
  string s = a;
  string t = b;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  string ans;
  if (ispermutation(a, b)) {
    ans = "array";
  } else if (issubseq(a, b)) {
    ans = "automaton";
  } else if (issubseq(s, t)) {
    ans = "both";
  } else {
    ans = "need tree";
  }
  cout << ans << "\n";
  return 0;
}
