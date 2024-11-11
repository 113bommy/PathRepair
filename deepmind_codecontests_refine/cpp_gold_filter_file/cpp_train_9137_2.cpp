#include <bits/stdc++.h>
using namespace std;

long long N;
string S;
int P;

long long solve(){
    if(P==2||P==5){
        long long res=0;
        for(int i=0;i<N;i++) if((S[N-i-1]-'0')%P==0) res+=N-i;
        return res;
    }
    vector<long long> val(P, 0);
    long long tenfactor=1;
    long long cur=0;
    val[cur]++;

    for(int i=0;i<N;i++){
        cur=(cur+(S[N-i-1]-'0')*tenfactor)%P;
        tenfactor=(tenfactor*10)%P;
        val[cur]++;
    }
    long long res=0;
    for(int p=0;p<P;p++) res+=val[p]*(val[p]-1)/2;
    return res;
}

int main(){
    cin >> N >> P >> S;
    cout << solve() << endl;
}
