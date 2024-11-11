#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  vector<string> v;
  cin >> n;
  for (int i = 0; i < int(n); i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  for (int i = 0; i < int(10); i++) {
    cout << "??" << i << ">>" << i << "??" << endl;
  }
  cout << "??>>?" << endl;
  for (int i = 0; i < int(9); i++) {
    cout << i << "?"
         << "<>" << i + 1 << endl;
  }
  cout << "9?>>?0" << endl;
  cout << "?<>0" << endl;
  cout << ">>??" << endl;
  return 0;
}
