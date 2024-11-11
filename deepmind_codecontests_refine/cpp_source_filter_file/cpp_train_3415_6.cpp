#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,l;
    cin>>n>>l;
    int s=n*l+n*(n-1)/2,min;
    if(l>0) min=s-l;
    else if(n+l<=0) min=-s+l+n-1
    else min=0;
    cout<<min<<endl;
    return 0;
}