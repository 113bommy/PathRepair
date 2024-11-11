#include <bits/stdc++.h>
using namespace std;
#define int long long
int main(){
    int n,k,s,t;
    int ans;
    cin>>n>>k;
    t = n/k;
    if(k%2==0){
        s = (n+(k/2))/k;
        ans = s*s*s + t*t*t;
    }
    else{
        ans = t*t*t;
    }
    cout<<ans<<endl;
}