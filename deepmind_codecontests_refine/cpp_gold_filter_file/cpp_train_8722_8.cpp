#include <iostream>
#include <string>
using namespace std;
int main(){
  string S[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
  string t;
  cin >> t;
  for(int i = 0; i < 7; i++ ){
    if(t == S[i]) cout << 7-i << endl;
  }
}
