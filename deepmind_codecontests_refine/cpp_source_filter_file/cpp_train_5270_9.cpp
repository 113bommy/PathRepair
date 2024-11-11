#include <bits/stdc++.h>
using namespace std;
string s;
int n;
queue<int> q;
bool consonant(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  int n = s.size();
  int c = 0;
  int count = 1;
  for (int i = 0; i < n; ++i) {
    if (consonant(s[i]))
      c = 0;
    else {
      if (s[i] == s[i - 1])
        count++;
      else
        count = 1;
      c++;
      if (c == 3) {
        if (count >= 3)
          c = 0;
        else {
          q.push(i);
          c = 1;
        }
      }
    }
  }
  if (q.empty())
    cout << s << "\n";
  else {
    for (int i = 0; i < n; ++i) {
      cout << s[i];
      if (!q.empty() && q.front() == i + 1) {
        cout << " ";
        q.pop();
      }
    }
  }
  return 0;
}
