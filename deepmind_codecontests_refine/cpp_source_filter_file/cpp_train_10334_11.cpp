#include <bits/stdc++.h>
using namespace std;
int n, k;
set<char> s{'a', 'e', 'i', 'o', 'u'};
bool rhyme(string a, string b) {
  int N = a.length(), cnt = 0, i;
  string str1, str2;
  for (i = N - 1; i >= 0; i--) {
    if (s.find(a[i]) != s.end()) cnt++;
    if (cnt == k) {
      str1 = a.substr(i);
      break;
    }
  }
  cnt = 0;
  N = b.length();
  for (i = N - 1; i >= 0; i--) {
    if (s.find(b[i]) != s.end()) cnt++;
    if (cnt == k) {
      str2 = b.substr(i);
      break;
    }
  }
  return (str1 == str2 && str1 == "");
}
int main() {
  cin >> n >> k;
  int aabb = 1, abab = 1, abba = 1;
  while (n--) {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a.length() < k || b.length() < k || c.length() < k || d.length() < k) {
      cout << "NO";
      return 0;
    }
    if (rhyme(a, b) && rhyme(c, d))
      aabb &= 1;
    else
      aabb = 0;
    if (rhyme(a, c) && rhyme(b, d))
      abab &= 1;
    else
      abab = 0;
    if (rhyme(a, d) && rhyme(c, b))
      abba &= 1;
    else
      abba = 0;
  }
  if (aabb & abab & abba)
    cout << "aaaa";
  else if (aabb == 1 && abab == 0 && abba == 0)
    cout << "aabb";
  else if (aabb == 0 && abab == 1 && abba == 0)
    cout << "abab";
  else if (aabb == 0 && abab == 0 && abba == 1)
    cout << "abba";
  else
    cout << "NO";
}
