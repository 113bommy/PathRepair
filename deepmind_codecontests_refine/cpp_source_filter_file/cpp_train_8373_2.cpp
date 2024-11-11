#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  bool flag = false;
  getline(cin, s1);
  getline(cin, s2);
  map<char, int> freq1;
  map<char, int> freq2;
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] != ' ') freq1[s1[i]]++;
  }
  for (int i = 0; i < s2.length(); i++) {
    if (s2[i] != ' ') freq2[s2[i]]++;
  }
  map<char, int>::iterator it1;
  map<char, int>::iterator it2;
  for (it2 = freq2.begin(); it2 != freq2.end(); it2++) {
    it1 = freq1.find(it2->first);
    if (it1 != freq1.end()) {
      if ((it2->second) <= it1->second) {
        flag = true;
      } else {
        flag = false;
        break;
      }
    } else {
      flag = false;
      break;
    }
  }
  if (flag)
    cout << "Yes\n";
  else
    cout << "No\n";
}
