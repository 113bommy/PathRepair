#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  reverse(s.begin(),s.end());
  string a[4]={"remaerd", "maerd", "esare", "resare"};
  bool can2=false;
  for(int i=0;i<s.size();){
    can2=false;
  	fir(int j=0;j<4;j++){
    	string d=a[j];
      if(s.sbstr(i,d.size())==d){
        can2=true;
      i+=d.size();
      }
    }
    if(can2==false){
    break;
    }
  }
  if(can2){cout << "YES" << endl;}
  else{cout << "NO" << endl;}
}

