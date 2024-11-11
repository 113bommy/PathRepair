#include <bits/stdc++.h>
using namespace std;
bool vowel(char x) { return string("aeiou").find(x) != string::npos; }
bool rhymes(const string &s1, const string &s2, int k) {
  int t1 = s1.size() - 1;
  int t2 = s2.size() - 1;
  int v = 0;
  while (t1 >= 0 && t2 >= 0 && v < k) {
    if (s1[t1] != s2[t2]) return false;
    if (vowel(s1[t1])) ++v;
    --t1;
    --t2;
  }
  return false;
}
int type_of_quatrian(int k) {
  int res = 0;
  static string ss[4];
  for (int i = 0; i < 4; ++i) cin >> ss[i];
  if (rhymes(ss[0], ss[1], k) && rhymes(ss[2], ss[3], k)) res |= 1;
  if (rhymes(ss[0], ss[2], k) && rhymes(ss[1], ss[3], k)) res |= 2;
  if (rhymes(ss[0], ss[3], k) && rhymes(ss[1], ss[2], k)) res |= 4;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  int ans = type_of_quatrian(k);
  for (int i = 1; ans != 0 && i < n; ++i) ans &= type_of_quatrian(k);
  switch (ans) {
    case 0:
      cout << "NO" << endl;
      break;
    case 1:
      cout << "aabb" << endl;
      break;
    case 2:
      cout << "abab" << endl;
      break;
    case 4:
      cout << "abba" << endl;
      break;
    case 7:
      cout << "aaaa" << endl;
      break;
    default:;
  }
  return 0;
}
