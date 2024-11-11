#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
int main(){
  int n; cin>>n; string s;
  while(n--){ cin>>s; mp[s]++; }
  cout<<"AC x "<<mp["AC"]<<endl;
  cout<<"WA x "<<mp["WA"]<<endl;
  cout<<"TLE x "<<mp["TLE"]<<endl;
  cout<<"RE x "<<mp["RE"]<<endl;
}