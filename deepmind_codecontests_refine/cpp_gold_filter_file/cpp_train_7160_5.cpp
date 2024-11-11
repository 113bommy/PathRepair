#include<bits/stdc++.h>
using namespace std;
int main(){
string S;
  cin>>S;
  int N=S.size();
  if(S.substr(0,(N-1)/2)==S.substr((N+3)/2-1,(N-1)/2)){
  
  cout<<"Yes"<<endl;
  }
   else{
   cout<<"No"<<endl;
   }

}
