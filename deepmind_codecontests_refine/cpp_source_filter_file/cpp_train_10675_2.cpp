#include <bits/stdc++.h>
const long long INF = 4e18L + 1;
const int IINF = 2e9 + 1;
const int limit = 1048576;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  string num;
  cin >> num;
  if (num[0] == '.') {
    num.insert(0, "0");
  }
  int dot = num.find(".");
  if (dot == int(string::npos)) {
    num.push_back('.');
    dot = num.size() - 1;
  }
  if (0) cout << "dot " << dot << "\n";
  int sig = num.find_first_of("123456789");
  if (0) cout << "sig " << sig << "\n";
  int exp = (dot > sig) ? dot - (sig + 1) : dot - sig;
  if (0) cout << "exp " << exp << "\n";
  num.erase(dot, 1);
  if (0) cout << "num after erase " << num << "\n";
  sig = num.find_first_of("123456789");
  if (0) cout << "new sig " << sig << "\n";
  num.insert(sig + 1, ".");
  if (0) cout << "num after insert " << num << "\n";
  int last_sig = num.find_last_not_of("0");
  if (0) cout << "last_sig " << last_sig << "\n";
  cout << num.substr(sig, last_sig - sig + 1);
  if (exp != 0) {
    cout << "E" << exp << "\n";
  } else {
    cout << "\n";
  }
  return 0;
}
