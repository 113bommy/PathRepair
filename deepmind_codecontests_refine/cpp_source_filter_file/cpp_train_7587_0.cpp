include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main (){
int a,b,x,az,bz,abh=0;
cin>>a>>b>>x;
//////////////////az//////////////////
if (x<a){
        az=a;
}
else {
        az=x/1000*a;
        if (x%1000!=0){
                az+=a;
        }
}
//////////////////bz//////////////////
if (x<b){
        bz=b;
}
else {
        bz=x/500*b;
        if (x%500!=0){
                bz+=b;
        }
}
/////////////////abh//////////////////
if (b*2<a){
        abh+=x/500*b;
        if (x%500!=0){
                abh+=min(a,b);
        }
}
else {  //b*2>a
        abh+=x/1000*a;
        if (x%1000!=0){
                if (x%1000<=500){
                        abh+=min(a,b);
                }
               else {
                        abh+=min(a,b*2);
                }
        }
}

int ans=min(abh,min(az,bz));
cout<<ans<<endl;
return 0;
}

