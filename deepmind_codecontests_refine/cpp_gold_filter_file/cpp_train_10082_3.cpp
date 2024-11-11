#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a[200000],ans[200000];
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=n-1;i>=0;i--){
        if((n-i)%2)ans[(n-i)/2]=a[i];
        else ans[n-((n-i)/2)]=a[i];
    }
    for(int i=0;i<n;i++){
        if(i!=n-1)cout<<ans[i]<<" ";
        else cout<<ans[i]<<endl;
    }
    return 0;
}

