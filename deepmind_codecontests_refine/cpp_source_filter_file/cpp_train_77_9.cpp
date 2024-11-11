#include<bits/stdc++.h>
using namespace std;
int main (){
  int N;cin >> N;
  map<string,int>m;
  for(int i=1;i<=N;i+=1){
    string s;cin>>s;
    m[s]++;
  }
  cout<<"AC x "<<M["AC"]<<endl;
  cout<<"WA x "<<M["WA"]<<endl;
  cout<<"TLE x "<<M["TLE"]<<endl;
  cout<<"RE x "<<M["RE"]<<endl;
  return 0;
}
