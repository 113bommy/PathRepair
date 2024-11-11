#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if((a-b>=-d&&a-b<=d&&b-c>=-d&&b-c<=d)||(c-a>=-d&&c-a<=d))cout<<"Yes"<<endl;
  else cout << "No" <<endl;
}