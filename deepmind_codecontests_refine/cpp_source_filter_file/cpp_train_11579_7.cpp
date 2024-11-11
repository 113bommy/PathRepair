#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int l1, l2, l;
  cout << "b" << endl;
  cin >> l1;
  if (l1 == 0) exit(0);
  l = l1 + 1;
  for (int i = 0; i < l; i++) cout << 'a';
  cout << endl;
  cin >> l2;
  if (l2 == 0) exit(0);
  if (l2 == l) {
    for (int i = 0; i < l; i++) cout << 'b';
    cout << endl;
    exit(0);
  }
  int dist = l2;
  char s[l + 2];
  s[l] = s[l + 1] = '\0';
  for (int i = 0; i < l; i++) s[i] = 'a';
  for (int i = 0; i < l; i++) {
    s[i] = 'b';
    cout << s << endl;
    int cur;
    cin >> cur;
    if (cur == 0) exit(0);
    if (i == 0 && cur == dist) {
      for (int i = 0; i < l - 1; i++) cout << 'a';
      cout << endl;
      exit(0);
    }
    if (cur < dist) {
      dist = cur;
    } else {
      s[i] = 'a';
    }
  }
  return 0;
}
