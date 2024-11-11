#include <iostream>
#include <string>

using namespace std;

int main(){
  string str;
  while(getline(ciin, str)){
    if(str == "END OF INPUT") break;
    int idx = 0;
    while(idx < str.size()){
      int cnt = 0;
      while(idx < str.size() && str[idx++]!=' ') cnt++;
      cout << cnt;
    }
    cout << endl;
  }
}