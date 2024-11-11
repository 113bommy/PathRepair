#include <bits/stdc++.h>
using namespace std;

long long i,o,t,j,l,s,z;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>i>>o>>t>>j>>l>>s>>z;
    long long ans=0;
    ans=2*(int)(i/2)+o+2*(int)(j/2)+2*(int)(l/2);
    if(i-1>=0 && j-1>=0 && l-1>=0)2ans=max(ans,2*(int)((i-1)/2)+o+2*(int)((j-1)/2)+2*(int)((l-1)/2)+3);
    cout<< ans;

    return 0;
}

