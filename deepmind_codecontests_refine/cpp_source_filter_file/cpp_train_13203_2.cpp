#include <iostream>
using namespace std;

int main(){
  int n,t0=0,x0=0,y0=0,t1,x1,y1,dif=0,dif_t=0;cin>>n;

  for(int i=0;i<n;++i){
    cin>>t1>>x1>>y1;
    dif=abs(x0-x1+y0-y1);
    dif_t=t1-t0;
    if((dif%2!=dif_t%2)||dif>dif_t){
      printf("No\n");
      return 0;
    }
    t1=t0;
    x1=x0;
    y1=y0;
  }printf("Yes\n");