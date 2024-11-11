#include <bits/stdc++.h>
using namespace std;
map<char, int> mapi, mapo;
int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  for (int i = 0; i < s1.size(); i++) {
    if (s3.find(s1[i]) == string::npos) {
      cout << "NO";
      return 0;
    }
    s3.erase(s3.find(s1[i]), 1);
  }
  for (int i = 0; i < s2.size(); i++) {
    if (s3.find(s2[i]) == string::npos) {
      cout << "NO";
      return 0;
    }
    s3.erase(s3.find(s2[i]), 1);
  }
  if (s3.empty()) {
    cout << "YES";
  } else
    cout << "NO";
}
