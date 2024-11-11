#include <bits/stdc++.h>
using namespace std;
int search(string nam[], int i) {
  int j = 0;
  for (; j < i; j++) {
    if (nam[j] == nam[i]) return 1;
  }
  return 0;
}
int main() {
  int n, num = 0, cnt = 0, found = 0;
  cin >> n;
  string *names = new string[n];
  for (int i = 0; i < n; i++) {
    cin >> names[i];
    found = search(names, i);
    if (found)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
