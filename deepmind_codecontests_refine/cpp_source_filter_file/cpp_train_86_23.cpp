#include<iostram>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if(a==b+c or b==a+c or c==a+b)cout<<"Yes\n";else cout<<"No\n";}