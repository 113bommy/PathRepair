#include<iostream>
using namespace std;

int main(){
long long a,b,c,d;
  cin>>a>>b>>c>>d;
  long long ans = max(a*c,max(a*d,max(b*c,max(b*d))));
  cout<<ans;
  return 0;
}
