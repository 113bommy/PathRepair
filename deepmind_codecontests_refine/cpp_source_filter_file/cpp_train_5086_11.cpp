#include<cstdio>
using namespace std;
int array[200005]={0};
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<max(a*b,c*d)<<endl;
}
