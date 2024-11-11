#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
vector<long long int> ss;
vector<long long int> aa;
int main() {
  long long int t;
  cin >> t;
  while (t > 0) {
    v.clear();
    ss.clear();
    aa.clear();
    string a, s;
    cin >> a >> s;
    for (long long int i = a.length() - 1; i >= 0; i--) {
      aa.push_back(a[i] - '0');
    }
    for (long long int i = s.length() - 1; i >= 0; i--) {
      ss.push_back(s[i] - '0');
    }
    long long int flg = 0;
    long long int i = 0, j = 0;
    while (i < aa.size()) {
      if (j >= ss.size()) {
        flg = 1;
        break;
      }
      if (ss[j] < aa[i]) {
        if (j + 1 >= ss.size()) {
          flg = 1;
          break;
        }
        long long int q = (ss[j + 1] * 10) + ss[j];
        long long int num = q - aa[i];
        if (num > 9 and num >= 0) {
          flg = 1;
          break;
        } else {
          v.push_back(num);
        }
        j = j + 2;
      } else {
        v.push_back(ss[j] - aa[i]);
        j++;
      }
      i++;
    }
    if (flg) {
      cout << "-1" << endl;
    } else {
      long long int ans = 0;
      if (j < ss.size()) {
        for (long long int i = j; i < ss.size(); i++) {
          v.push_back(ss[i]);
        }
      }
      long long int i = v.size() - 1;
      while (v[i] == 0) {
        i--;
      }
      long long int c = 0;
      for (long long int j = i; j >= 0; j--) {
        cout << v[j];
        c++;
      }
      if (c == 0) {
        cout << 0;
      }
      cout << endl;
    }
    t--;
  }
}
