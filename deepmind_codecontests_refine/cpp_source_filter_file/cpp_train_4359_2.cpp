#include<iostram>
using namespace std;
int main(){
  int a,b,c;cin>>a>>b>>c;
  if(a==b and b==c)cout<<1<<endl;
  else if(a!=b and b!=c and a!=c)cout<<3<<endl;
  else cout<<2<<endl;
}