#include<bits/stdc++.h>
using namespace std;
int main(){
  string a,b,c;
  cin>>a>>b>>c;
  char d='A'-'a';
  cout<<(char)(a[0]+d)<<(char)(b[0]+d)<<(char)(c[0]+d)<<endl;
}