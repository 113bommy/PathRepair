#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i;
    cin>>n;
    for(i=0;i<=n/7;i++) if((n-i*7)%4==0) break;
    cout<<(i<=n/7?"Yes":"No")<<endl;
    return 0;
}