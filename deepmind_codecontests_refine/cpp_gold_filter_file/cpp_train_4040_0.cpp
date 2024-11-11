#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,M; cin>>N>>M;
    vector<vector<int>> v(100005);
    for(int i=0;i<N;i++){
        int a,b; cin>>a>>b;
        v[a].push_back(b);
    }

    int ans=0;
    priority_queue<int> Q;
    for(int i=1;i<=M;i++){
        for(int x:v[i]) Q.push(x);
        if(!Q.empty()){
            ans+=Q.top(); Q.pop();
        }
    }
    cout<<ans<<endl;

    return 0;
}