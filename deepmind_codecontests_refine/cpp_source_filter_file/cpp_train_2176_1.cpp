include <iostream>
#include <string>

using namespace std;

int main(){
  string s;

  while(  cin >> s){
  string joi = "JOI",ioi = "IOI";
  int num_joi=0,num_ioi=0;

  for(int i=0;i < s.size()-2 ;i++) {
    string sub= s.substr(i,3) ;
    if(sub == joi) num_joi++;
    if(sub == ioi) num_ioi++;
  }

  cout << num_joi <<"\n" << num_ioi << "\n";
  }
}