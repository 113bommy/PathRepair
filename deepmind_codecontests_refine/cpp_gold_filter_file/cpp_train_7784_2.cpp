#include<bits/stdc++.h>
using namespace std;
int main(){int i,n,m,l,r,c;
cin>>n>>m;
c=m;
l=1;
r=m+2;
for(i=1;i<=m;i++){
    if(i%2){
        cout<<l<<" "<<l+c<<"\n";
        c--;l++;
    }else{cout<<r<<" "<<r+c<<"\n";
        c--;r++;
    }
}
    return 0;
}