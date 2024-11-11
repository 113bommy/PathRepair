#include <bits/stdc++.h>
using namespace std;

int main(){
  string today;
  cin>>today;
  string week[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
  for(int i=0;i<7;i++){
    if(week[i]==today){
      cout<7-i<<endl;
    }
  }
}