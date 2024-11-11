#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
typedef long long int i64;
int main(){
    int N;cin>>N;
    int A[3][N];
    REP(i,3)REP(j,N) cin>>A[i][j];
    REP(i,3) sort(A[i],A[i]+N);
    i64 sum=0;
    REP(i,N) sum+=(lower_bound(A[0],A[0]+N,A[1][i])-A[0])*(A[2]+N-upper_bound(A[2],A[2]+N,A[1][i]));
    cout<<sum<<endl;
}