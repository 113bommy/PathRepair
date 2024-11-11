#include<bits/stdc++.h>
using namespace std;
int N,c;
string S;
int main(){
  cin>>N>>S;
  for(char i='0';i<='9';i++){
    auto it_i = S.find(i);
    if(it_i==string::npos)continue;
    for(char j='0'; j<='9'; j++){
      auto it_j=S.find(j,it_i+1);
      if(it_j==string::npos)continue;
      for(char k='0';k<='9';k++)if(S.find(k,it_j+1)!=string::npos)c++;
    }
  }
  cout<<c<<endl;
  return 0;
}
