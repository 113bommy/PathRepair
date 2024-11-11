#include "bits/stdc++.h"
using namespace std;
#define PB push_back
#define MP make_pair
#define ALL(a)  (a).begin(),(a).end()
#define REP(i,n) for(int i=0;i<(n);i++)
int d[100][100];
int main(){
    int n,m;
    int a[1000],b[1000],c[1000];
    cin>>n>>m;
    REP(i,n)REP(j,n)d[i][j]=1e9;
    REP(i,n)d[i][i]=0;
    REP(i,m){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--;b[i]--;
        d[a[i]][b[i]]=d[b[i]][a[i]]=c[i];
    }
    REP(k,n)
        REP(i,n)
            REP(j,n)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

    int cnt=0;
    REP(i,m)if(d[a[i]][b[i]]<c[i])cnt++;
    cout<<cnt<<endl;
}