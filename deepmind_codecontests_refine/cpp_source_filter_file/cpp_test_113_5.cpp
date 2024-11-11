#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    long long n1, n2, num1 = 0, num2 = 0;
    cin >> s1;
    cin >> n1;
    cin >> s2;
    cin >> n2;
    if (s1.size() < s2.size())
      for (int i = 0;; i < n1) {
        s1 += '0';
        n1--;
        if (s1.size() == s2.size()) break;
      }
    else if (s1.size() > s2.size())
      for (int i = 0;; i < n2) {
        s2 += '0';
        n2--;
        if (s1.size() == s2.size()) break;
      }
    if (n1 > n2)
      cout << '>' << endl;
    else if (n1 < n2)
      cout << '<' << endl;
    else {
      for (int i = 0; i < s1.size(); i++) {
        num1 *= 10;
        num1 += s1[0] - 48;
        num2 *= 10;
        num2 += s2[0] - 48;
        if (num1 > num2) {
          cout << '>' << endl;
          break;
        } else if (num1 < num2) {
          cout << '<' << endl;
          break;
        } else if (i == s1.size() - 1)
          cout << '=' << endl;
      }
    }
  }
  return 0;
}
