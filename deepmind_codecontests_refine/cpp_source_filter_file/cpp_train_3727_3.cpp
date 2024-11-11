#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef pair<int,int> pii;
const int MN = 2e5+5;
int N,A[MN],B[MN];
priority_queue<pii> PQ;
int main()
{
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++){
        cin >> B[i];
        if(B[i]<A[i]){
            cout << -1;
            return 0;
        }
        if(B[i]>A[i]) PQ.emplace(B[i],i);
    }
    int v,x;
    ll ans=0;
    while(PQ.size()){
        tie(v,x) = PQ.top();
        PQ.pop();
        if(B[x]-(B[(x-1+N)%N]+B[(x+1)%N])<A[x]){
            cout << -1;
            return 0;
        }
        int cnt = (B[x]-A[x])/(B[(x-1+N)%N]+B[(x+1)%N]);
        B[x] -= cnt*(B[(x-1+N)%N]+B[(x+1)%N]);
        ans += cnt;
        if(B[x]>A[x]) PQ.emplace(B[x],x);
    }
    cout << ans;
}
