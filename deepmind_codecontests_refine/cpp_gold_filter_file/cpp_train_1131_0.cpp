#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int n;
  cin >> n;
  cin.ignore();
  for(int i=0;i<n;i++){
    getline(cin,s);
    while(s.find("Hoshino")!=string::npos){
      s.replace(s.find("Hoshino"),7,"Hoshina");
    }
    cout<<s<<endl;
  }
}