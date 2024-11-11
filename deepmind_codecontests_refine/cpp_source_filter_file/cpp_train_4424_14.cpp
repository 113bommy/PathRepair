#include <bits/stdc++.h>
using namespace std;
unsigned long long mod = 1000000007;
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  string inp;
  bool done = false;
  cin >> inp;
  for (int pos = 0; pos < int((inp).size()); ++pos) {
    for (int len = 0; pos + len < int((inp).size()); ++len) {
      string now = inp;
      now.erase(pos, len);
      if (now == "CODEFORCES") {
        done = true;
        break;
      }
    }
    if (done) break;
  }
  if (done)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
  return 0;
}
