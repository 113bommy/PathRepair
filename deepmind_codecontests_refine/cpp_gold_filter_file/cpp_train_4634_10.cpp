#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  regex b("h.*e.*l.*l.*o");
  if (regex_search(a, b))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
