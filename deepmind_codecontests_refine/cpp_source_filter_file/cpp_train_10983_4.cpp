#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int cl = 0;
  int cu = 0;
  set<char> st;
  for (auto &e : a) {
    if (islower(e))
      cl += 1;
    else
      cu += 1;
  }
  if (cl > cu) {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    cout << a << endl;
  } else {
    transform(a.begin(), a.end(), a.begin(), ::toupper);
    cout << a << endl;
  }
}
