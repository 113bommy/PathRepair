#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if ((s.find("AB") == string ::npos) || (s.find("BA") == string ::npos)) {
    cout << "NO" << endl;
  } else {
    int idx = s.find("AB");
    if (s.find("BA", idx + 2) != string ::npos) {
      cout << "YES" << endl;
      return 0;
    }
    idx = s.find("BA");
    if (s.find("AB", idx + 2) != string ::npos) {
      cout << "YES" << endl;
      return 0;
    }
    cout << "NO" << endl;
  }
  return 0;
}
