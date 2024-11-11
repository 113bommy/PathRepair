#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int n = 0, i = 0, e = 0, t = 0;
  for (int j = 0; j <= a.length() - 1; j++) {
    if (a[j] == 'n') n++;
    if (a[j] == 'i') i++;
    if (a[j] == 'e') e++;
    if (a[j] == 't') t++;
  }
  vector<int> b;
  b.push_back((n / 3) + 1);
  b.push_back(e / 3);
  b.push_back(t);
  b.push_back(i);
  sort(b.begin(), b.end());
  cout << b[0] << endl;
}
