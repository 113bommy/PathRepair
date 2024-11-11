#include <iostream>
using namespace std;
int main() {
  int n;
  string str;
  cin >> n >> str;
  for(int i=0; i<str.size(); i++) {
    s[i]+=n;
    if(s[i]>90)
      s[i]-26;
  }
  cout << str << endl;
}
