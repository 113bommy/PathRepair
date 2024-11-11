#include <iostream>
using namespace std;
int main(){
  string s;
  cin >> s;
  int a;
  if(s[0] == 'R') a++;
  if(s[1] == 'R') a++;
  if(s[2] == 'R') a++;
  if(a == 2 && s[1] = 'S') a--;
  cout << a << "\n"
}