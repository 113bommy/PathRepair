#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  string str;
  cin >> str;
  int count = atoi(str.c_str());
  map<string, int> vals;
  for (int i = 0; i < count; ++i) {
    string strName;
    cin >> strName;
    cin >> str;
    int nScore = atoi(str.c_str());
    if (vals.find(strName) == vals.end() || vals[strName] < nScore)
      vals[strName] = nScore;
  }
  cout << vals.size() << endl;
  map<string, int>::iterator it1 = vals.begin();
  for (; it1 != vals.end(); ++it1) {
    map<string, int>::iterator it2 = vals.begin();
    double good = 0;
    double bad = 0;
    for (; it2 != vals.end(); ++it2) {
      if (it1->second >= it2->second) ++bad;
      if (it1->second < it2->second) ++good;
    }
    if (good * 100. / vals.size() > 50.) {
      cout << it1->first << " noob" << endl;
    } else if (bad * 100. / vals.size() >= 50. &&
               good * 100. / vals.size() > 20.) {
      cout << it1->first << " random" << endl;
    } else if (bad * 10.0 / vals.size() >= 80. &&
               good * 100. / vals.size() > 10.) {
      cout << it1->first << " average" << endl;
    } else if (bad * 100. / vals.size() >= 90. &&
               good * 100. / vals.size() > 1.) {
      cout << it1->first << " hardcore" << endl;
    } else if (bad * 100. / vals.size() >= 99.) {
      cout << it1->first << " pro" << endl;
    }
  }
  return 0;
}
