#include<iostrea>
using namespace std;
int main(){
 int n,s=0,x,y;
  cin>>n>>x;
  for(int i=1;i<n;i++){
    cin>>y;
    if(y==x)s++,y=-1;
    x=y;}cout<<s<<endl;}