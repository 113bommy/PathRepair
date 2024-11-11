#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,K,S;
    cin>>N>>K>>S;
    for(int j=0; j<K; j++) cout<<S<<" ";
    for(int j=0; j<N-K; j++) 
        if(S==1e9) cout<<S-1<<" ";
        else cout<<S+1<<" ";
    return 0;
}
