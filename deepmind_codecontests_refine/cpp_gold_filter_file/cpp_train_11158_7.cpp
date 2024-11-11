#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  string abc = "abc";
  while (next_permutation(abc.begin(), abc.end())) {
    string res1 = string(n, abc[0]) + string(n, abc[1]) + string(n, abc[2]);
    if (res1.find(s) == string::npos && res1.find(t) == string::npos) {
      cout << "YES" << endl;
      cout << res1 << endl;
      return 0;
    }
    string res2 = "";
    for (int i = 0; i < n; i++) res2 += abc;
    if (res2.find(s) == string::npos && res2.find(t) == string::npos) {
      cout << "YES" << endl;
      cout << res2 << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
