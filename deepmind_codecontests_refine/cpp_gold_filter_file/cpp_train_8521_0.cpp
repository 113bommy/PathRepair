#include<bits/stdc++.h>
using namespace std;
vector<int> v[101010];
int n,k,a,y,i=1;
int s(int x,int p=0){
    int r=0;
    for(auto to:v[x])r=max(r,s(to,x));
    if(++r>=k&&p)a++,r=0;
    return r;
}
int main(){
    cin>>n>>k>>y;
    if(y!=1)a++;
    for(;i<n;i++){
        cin>>y;
        v[y-1].push_back(i);
    }
    s(0);
    cout<<a;
}