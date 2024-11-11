#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,p,s=0,m=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p;
        s+=p;
        m=max(m,p);
    }
    cout<<s-m/2<<endl;
    return 0;
}