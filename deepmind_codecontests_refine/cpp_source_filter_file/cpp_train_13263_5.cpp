#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  s += ',';
  set<int> se;
  int k = s.find(',');
  while (k != string::npos) {
    char s1[100];
    for (int i = 0; i < 100; i++) {
      s1[i] = 0;
    }
    for (int i = 0; i < k; i++) {
      s1[i] = s[i];
    }
    int p = atoi(s1);
    if (!se.count(p)) {
      se.insert(p);
    }
    s.erase(0, k + 1);
    k = s.find(',');
  }
  set<int>::iterator ite = se.begin();
  int beg = *se.begin();
  for (set<int>::iterator iter = ++se.begin(); iter != se.end(); iter++) {
    if ((*iter) == ((*ite) + 1)) {
      ite = iter;
    } else {
      if (*(ite)-beg > 1) {
        cout << beg << '-' << *(ite);
      } else {
        cout << beg;
      }
      cout << ',';
      beg = (*iter);
      ite = iter;
    }
  }
  if (*(ite)-beg > 1) {
    cout << beg << '-' << *(ite);
  } else {
    cout << beg;
  }
  return 0;
}
