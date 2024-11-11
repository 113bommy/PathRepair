#include<bits/stdc++.h>
using namespace std;

int mmain(){
  string s;cin>>s;
  int cnt=0;
  for(int i=0;i<3;i++){
    if(s[i]=='o')cnt++;
  }
  cout<<700+cnt*100<<endl;
}