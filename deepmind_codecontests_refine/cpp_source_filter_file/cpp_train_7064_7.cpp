#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  cout << ((s.find('C', s.find('F')) != -1) ? "Yes" : "No") << endl;
}
