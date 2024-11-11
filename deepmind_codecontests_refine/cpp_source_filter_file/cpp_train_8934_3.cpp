#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
const int maxn = 101010;
int trie[maxn][2], nd = 1;
void add(char x[]){
    int cur = 0;
    for(int e = 0; x[e]; e++){
        int & v = trie[cur][x[e]-'0'];
        if(v == -1) v = nd++;
        cur = v;
    }
}
long long l;
long long solve(int cur, long long v){
    if(cur == -1){
        if(l >= v) return ((l + 1 - h)&(-(l + 1 - h)));
        return 0;
    }
    return solve(trie[cur][0], v+1)^solve(trie[cur][1], v+1);
}
char d[maxn];
int main(){
    memset(trie, -1, sizeof(trie));
    int n;
    cin >> n >> l;
    for(int e = 0; e < n; e++){
        scanf("%s", d);
        add(d);
    }
    if(solve(0, 0) == 0) cout << "Bob" << endl;
    else cout << "Alice" << endl;
    return 0;
}
