#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,cnt=0;cin>>n;
    for(int i=1;i<=n;i++){int l, r;cin>>l>>r;cnt+=r-l+1;}
    cout<<cnt<<endl;
}