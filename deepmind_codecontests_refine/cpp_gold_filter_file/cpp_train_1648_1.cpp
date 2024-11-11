#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t,n;
  cin >> s >> t;
  n=s+s;
  if(n.find(t)<s.length()) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
