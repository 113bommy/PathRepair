#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if (s.find('0') != -1) {
    cout << "YES" << endl;
    cout << 0 << endl;
    return 0;
  } else if (s.find('8') != -1) {
    cout << "YES" << endl;
    cout << 8 << endl;
    return 0;
  } else {
    vector<char> v;
    {
      if (s.find('2') != -1) v.push_back('2');
      if (s.find('4') != -1) v.push_back('4');
      if (s.find('6') != -1) v.push_back('6');
    }
    while (v.size() != 0) {
      string a = "00";
      a[1] = v.back();
      for (long long i = 0; i < s.find_last_of(v.back()); i++) {
        a[0] = s[i];
        if (stoi(a) % 8 == 0) {
          cout << "YES" << endl;
          cout << a << endl;
          return 0;
        }
      }
      string b = "000";
      b[2] = v.back();
      for (long long i = 0; i < s.find_last_of(v.back()); i++)
        for (long long j = i + 1; i < s.find_last_of(v.back()); i++) {
          b[0] = s[i];
          b[1] = s[j];
          if (stoi(b) % 8 == 0) {
            cout << "YES" << endl;
            cout << b << endl;
            return 0;
          }
        }
      v.pop_back();
    }
  }
  cout << "NO" << endl;
  return 0;
}
