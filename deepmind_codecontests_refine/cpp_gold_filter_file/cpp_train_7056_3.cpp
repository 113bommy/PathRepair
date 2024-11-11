#include "bits/stdc++.h"
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl

int main() {
  string s; 
  cin >> s;
  string t;
  int q; 
  cin >> q;
  while (q--) {
    int type; 
     cin >> type;
    if (type == 1) {
      swap(s, t);
    } 
    else {
      int f; char c;
       cin >> f >> c;
      if (f == 1) {
        t.push_back(c);
      } else {
        s.push_back(c);
      }
    }
  }
  
  reverse(t.begin(),t.end());
  cout << t + s << endl;
  
   }
 
