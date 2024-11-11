#include<bits/stdc++.h>
int main(){
  string s[4];
  long long k,a[4]={};
  std::cin>>s[0]>>k;
  for(size_t i=0;i<3;++i) s[i+1]=s[i]+s[0];
  for(size_t i=0;i<4;++i) for(size_t j=0;j<s[i].length()-1;++j) if(s[i][j]==s[i][j+1]) ++a[i],s[i][j+1]='.';
  if(k&1) std::cout<<a[0]+(a[2]-a[0])*(k/2)<<std::endl;
  else std::cout<<a[1]+(a[3]-a[1])*(k/2-1)<<std::endl;
}