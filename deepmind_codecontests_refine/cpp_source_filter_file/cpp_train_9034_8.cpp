#include<bits/stdc++.h>
using namespace std;
int main(){
 string s,t;
  cin>>s>>t;
  ll jwb=0;
  for(int i=0;i<3;i++)if(s[i]==t[i])jwb++;
  cout << jwb <<endl;
}