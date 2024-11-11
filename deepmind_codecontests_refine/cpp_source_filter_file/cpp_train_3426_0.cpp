//02
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  for(int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f,a|b|c|d|e|f;){
    int x=a+d;
    int y=b+e;
    int z=c+f;
    int xt=(x-1)/3;
    int yt=(y-1)/3;
    int zt=(z-1)/3;
    x-=xt*3;
    y-=yt*3;
    z-=zt*3;
    int ar[]={x,y,z};
    sort(ar,ar+3);
    int ex=max(ar[0],count(ar,ar+3,3));
    cout<<xt+yt+zt+ex<<endl;
  }
  return 0;
}
    