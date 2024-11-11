#include <bits/stdc++.h>
using namespace std;
int a[100];
int main() {
  int n, k;
  cin >> n >> k;
  string a;
  cin >> a;
  map<char, int> m;
  for (int i = 0; i < a.size(); i++) {
    m[a[i]] = i;
  }
  int door = 0;
  bool fl = true;
  map<char, bool> bo;
  for (int i = 0; i < a.size(); i++) {
    if (!bo[a[i]]) bo[a[i]] = 1, door++;
    if (door > k) {
      fl = false;
      break;
    }
    if (m[a[i]] == i) door--;
  }
  if (fl)
    cout << "YES";
  else
    cout << "NO";
}
