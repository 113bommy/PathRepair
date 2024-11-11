#include<bits/stdc++.h>
using namespace std;
int main() {
  string s; cin >> s;
  cout << ((s.find('F', s.find('C')) != -1) ? "Yes" : "No") << endl;
}