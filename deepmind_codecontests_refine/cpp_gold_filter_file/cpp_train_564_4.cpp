#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> graph[1000];
long long parent[1000];
void here_we_go_again() {
  bool array = true;
  bool both = true;
  bool automaton = false;
  string s, t;
  cin >> s >> t;
  vector<int> h1(26, 0), h2(26, 0);
  int i, sn = s.length(), tn = t.length();
  for (i = 0; i < sn; i++) h1[s[i] - 'a']++;
  for (i = 0; i < tn; i++) h2[t[i] - 'a']++;
  long long j = 0;
  for (i = 0; i < sn and j < tn; i++) {
    if (s[i] == t[j]) j++;
    if (j == tn) automaton = (automaton or true);
  }
  for (i = 0; i < 26; i++) {
    array = (array and h1[i] == h2[i]);
    both = (both and h1[i] >= h2[i]);
  }
  if (automaton)
    cout << "automaton"
         << "\n";
  else if (array)
    cout << "array"
         << "\n";
  else if (both)
    cout << "both"
         << "\n";
  else
    cout << "need tree"
         << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) here_we_go_again();
  return 0;
}
