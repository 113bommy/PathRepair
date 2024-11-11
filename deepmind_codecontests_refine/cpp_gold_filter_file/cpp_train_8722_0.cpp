#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  vector<string> day(8);
  day = {" ","SAT","FRI","THU","WED","TUE","MON","SUN"};
  for(int i=1; i<8; i++){
    if(day[i] == s){
      cout << i << endl;
    }
  }
}
