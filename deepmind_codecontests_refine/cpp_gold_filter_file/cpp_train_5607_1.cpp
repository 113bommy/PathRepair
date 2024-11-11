#include<cstdio>
#include<iostream>
using namespace std;
int x,y,ans=0;
inline int abs(int x) {return x<0 ? -x:x;}
int main() {
    cin>>x>>y;
    if(x==-y) ans=1;
    else if(abs(x)<abs(y)) ans=abs(y)-abs(x)+(x<0)+(y<0);
    else ans=abs(x)-abs(y)+(x>0)+(y>0);
    printf("%d\n",ans);
    return 0;
}