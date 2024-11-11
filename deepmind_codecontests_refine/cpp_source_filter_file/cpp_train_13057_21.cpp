#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  long long int t;
  cin >> t;
  while (t--) {
    long long int flag;
    string s;
    vector<long long int> v;
    cin >> s;
    for (long long int i = 1; i <= s.size(); i++) {
      if (s.size() % i == 0) {
        for (long long int j = 0; j < s.size() / i; j++) {
          flag = 0;
          for (long long int k = j; k < s.size(); k += s.size() / i) {
            if (s[k] == 'O') {
              flag = 1;
              break;
            }
          }
          if (flag == 0) {
            v.push_back(i);
            break;
          }
        }
      }
    }
    cout << v.size() << " ";
    for (long long int i = 0; i < v.size(); i++) {
      cout << v[i] << "X" << s.size() / v[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
