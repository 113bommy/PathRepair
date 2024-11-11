#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int> s(4);
  for(int i=0;i<4;i++) cin>>s[i];
  sort(s.begin(),s.end());
  bool x=s[0]==1&&s[1]==4&&s[2]==7&&s[3]==9;
  if(x) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
