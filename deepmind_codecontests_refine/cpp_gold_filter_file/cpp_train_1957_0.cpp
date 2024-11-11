#include <iostream>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  for(int i=0; i<s.size(); i++) {
    s[i]+=n;
    if(s[i]>90)
      s[i]-=26;
  }
  cout << s << endl;
}
