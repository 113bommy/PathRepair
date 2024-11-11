#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<climits>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<set>
#include<stack>
#include<functional>
#include<queue>
using namespace std;
#define int long long long

signed main(){
    int N,T[10000];
    while(cin>>N,N){
        for(int i=0;i<N;i++) cin>>T[i];
        sort(T,T+N);
        int ans=0,sum=0;
        for(int i=0;i<N;i++){
            ans += sum; sum += T[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}