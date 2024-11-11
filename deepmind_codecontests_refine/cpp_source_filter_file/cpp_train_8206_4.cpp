#include<bits/stdc++.h>
using namespace std;
long long n,m,s,x,b[20010];
int main(){
    cin>>n;
    for(i=0;cin>>x;i++){
        if(!i) b[i]=x;
        else b[i]=b[i-1]+x;
        s+=x;
    }
    if(b[0]>s-b[0]) m=b[0]+b[0]-s;
    else m=s-b[0]-b[0];
    for(int i=1;i<(n-1);i++)
        m=max(m,abs(s-b[i]-b[i]));
    cout<<m<<endl;
    return 0;
} 