#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, l1, l2, k;
  string str, s = "<3", temp;
  cin >> n;
  getline(cin, temp);
  for (i = 0; i < n; i++) {
    getline(cin, temp);
    s.append(temp + "<3");
  }
  getline(cin, str);
  l1 = s.size();
  l2 = str.size();
  for (i = 0, k = 0; i < l1, k < l2; i++, k++) {
    while (str[k] != s[i] && k < l2) k++;
  }
  if (i == l1)
    cout << "yes";
  else
    cout << "no";
  return 0;
}
