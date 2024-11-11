#include<bits/stdc++.h>
using namespace std;

int main(){
int a,b,c;
  cin>>a>>b>>c;
  if(b>=c)
    cout<<"delicious"<<endl;
  else if(a+b<c)
    cout<<"dangerous"<endl;
  else
    cout<<"safe"<<endl;
}