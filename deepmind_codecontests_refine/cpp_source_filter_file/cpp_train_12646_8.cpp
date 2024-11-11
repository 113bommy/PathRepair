#include <bits/stdc++.h>
using namespace std;
bool jbk[256], b = true;
int main() {
  int n;
  string a;
  cin >> n;
  cin >> a;
  for (int i = 0; i < a.length(); i++) jbk[a[i]++];
  for (int i = 'A'; i < 'Z'; i++)
    if (!jbk[i] && !jbk[i + 'a' - 'A']) b = false;
  if (b)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
