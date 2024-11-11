#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ll lonf lonf
#define PB push_back
using namespace std;
int main(){
    ll N,K;
    ll T[100000];
    cin>>N>>K;
    FOR(i,0,N){
        cin>>T[i];
    }
    ll S=T[N-1]-T[0];
    vector<ll> V;
    FOR(i,1,N){
        V.PB(T[i]-T[i-1]);
    }
    sort(V.rbegin(),V.rend());
    FOR(i,0,K-1){
        S-=V[i];
    }
    cout<<S+K<<endl;
    return 0;
}
