#include <bits/stdc++.h>
const int MX = 1e9;
using namespace std;
int n, s;
string f;
vector<string> outs;
vector<int> outi;
multiset<int> ms;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> f;
    if (f == "insert") {
      cin >> s;
      ms.insert(s);
      outs.push_back(f);
      outi.push_back(s);
    } else if (f == "getMin") {
      cin >> s;
      while (*ms.begin() < s && ms.size() > 0) {
        outs.push_back("removeMin");
        outi.push_back(-2);
        ms.erase(ms.begin());
      }
      if (ms.size() == 0 || *ms.begin() > s) {
        outs.push_back("insert");
        outi.push_back(s);
        ms.insert(s);
      }
      outs.push_back(f);
      outi.push_back(s);
    } else if (f == "removeMin") {
      if (ms.size() == 0) {
        ms.insert(1);
        outs.push_back("insert");
        outi.push_back(1);
      }
      ms.erase(ms.begin());
      outs.push_back(f);
      outi.push_back(-2);
    }
  }
  cout << outs.size() << endl;
  for (int i = 0; i < outs.size(); i++) {
    if (outi[i] != -2)
      cout << outs[i] << " " << outi[i] << "\n";
    else
      cout << "removeMin"
           << "\n";
  }
}
