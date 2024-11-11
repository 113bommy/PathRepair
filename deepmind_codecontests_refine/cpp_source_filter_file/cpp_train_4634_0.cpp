#include <bits/stdc++.h>
long long int t;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char ch[5] = {'h', 'e', 'l', 'l', 'o'};
  int c = 0;
  string s;
  cin >> s;
  int n = 0;
  char x = ch[n];
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == x && c < 6) {
      c++;
      x = ch[++n];
    }
  }
  if (c == 5) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
