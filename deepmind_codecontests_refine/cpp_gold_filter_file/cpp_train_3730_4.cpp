#include<bits/stdc++.h>
using namespace std;
int main(){
  int a=0;string s;cin>>s;
  for(int i=0;i<3;i++)
    if(s.at(i)=='o')a++;
  cout<<700+a*100<<endl;
}