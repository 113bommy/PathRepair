#include <bits/stdC++.h>
using namespace std;
int main(){
    int n,r,k;cin>>k>>n;
    if (k>=10)cout<<n;
    else cout<<n+100*(10-k);}
