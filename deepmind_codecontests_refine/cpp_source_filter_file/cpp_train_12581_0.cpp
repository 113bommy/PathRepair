#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  cout << s.find("z") - s.rfind("A") + 1 << endl;
}
