#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string non = "1";
  long long zeroes = 0;
  int n;
  cin >> n;
  while (n--) {
    string in;
    cin >> in;
    if (in == "0") {
      cout << in << "\n";
      return 0;
    }
    bool good = false;
    int ones = 0;
    int zero = 0;
    for (int i = 0; i < in.size(); i++) {
      if (ones == 0 && in[i] == '1') {
        ones++;
      } else if (in[i] != '0') {
        non = in;
        good = true;
        break;
      } else {
        zero++;
      }
    }
    if (!good) {
      zeroes += zero;
    }
  }
  cout << non;
  while (zeroes--) {
    cout << "0";
  }
  cout << "\n";
}
