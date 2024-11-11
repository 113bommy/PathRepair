#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3;
bool vowel(char ch) {
  if (ch <= 'z' && ch >= 'a') ch += ('A' - 'a');
  if (ch == 'A' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'E')
    return true;
  return false;
}
bool syl(string s, int a) {
  int count1 = 0;
  for (int i = 0; i < s.size(); i++)
    if ((s[i] <= 'Z' && s[i] >= 'A') || (s[i] <= 'z' && s[i] >= 'a'))
      count1 += vowel(s[i]);
  return count1 == a;
}
int main() {
  getline(cin, s1);
  getline(cin, s2);
  getline(cin, s3);
  if (syl(s1, 5) && syl(s2, 7) && syl(s3, 5))
    cout << "YES";
  else
    cout << "NO";
}
