#include <bits/stdc++.h>
using namespace std;
set<char> a1;
set<char> a2;
long long int freq1[26], freq2[26];
bool checktree(string s1, string s2, long long int l1, long long int l2) {
  long long int i;
  for (i = 0; i < 26; i++) {
    if (freq2[i] > freq1[i]) return true;
  }
  return false;
}
bool checkauto(string s1, string s2, long long int l1, long long int l2) {
  long long int i, j = 0;
  if (l1 == l2) return false;
  for (i = 0; i < l1; i++) {
    if (s1[i] == s2[j]) j++;
  }
  if (j == l2) return true;
  return false;
}
bool checkarray(string s1, string s2, long long int l1, long long int l2) {
  long long int i;
  if (l1 != l2) return false;
  for (i = 0; i < 26; i++) {
    if (freq1[i] != freq2[i]) return false;
  }
  return true;
}
int main() {
  memset(freq1, 0, sizeof(freq1));
  memset(freq2, 0, sizeof(freq2));
  string s1, s2;
  cin >> s1;
  cin >> s2;
  long long int i, l1 = s1.size(), l2 = s2.size();
  for (i = 0; i < l1; i++) freq1[s1[i] - 'a']++;
  for (i = 0; i < l2; i++) freq2[s2[i] - 'a']++;
  bool cond = checktree(s1, s2, l1, l2);
  if (cond) {
    cout << "need tree\n";
    return 0;
  }
  bool cond2, cond3;
  cond2 = checkauto(s1, s2, l1, l2);
  if (cond2) {
    cout << "automaton\n";
    return 0;
  }
  cond3 = checkarray(s1, s2, l1, l2);
  if (cond3) {
    cout << "array\n";
    return 0;
  }
  cout << "both\n";
}
