#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, s1;
  s = "Bulbasaur";
  cin >> s1;
  map<char, long long int> m, m1;
  for (long long int i{0}; i < s.size(); i++) m[s[i]]++;
  for (long long int i{0}; i < s1.size(); i++) m1[s1[i]]++;
  map<char, long long int>::iterator itr, itr1;
  vector<long long int> vec;
  for (itr = m.begin(); itr != m.end(); ++itr) {
    int flag{1};
    for (itr1 = m1.begin(); itr1 != m1.end(); ++itr1) {
      if (itr1->first == itr->first) {
        if (itr1->first == 'a' || itr1->first == 'u') {
          vec.push_back((itr1->second) / 2);
        } else
          vec.push_back(itr1->second);
        flag = 2;
      }
    }
    if (flag == 1) vec.push_back(0);
  }
  long long int mimn{100001};
  for (int i{0}; i < vec.size(); i++) {
    mimn = min(mimn, vec[i]);
  }
  cout << mimn << '\n';
  return 0;
}
