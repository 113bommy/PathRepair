#include < bits/stdc++.h >

using namespace std;

int main(){
int n,m;cin>>n>>m;
priority_queue <long long> a;
for(int i=0;i<n;i++){
    long long b;
    cin>>b;
    a.push(b);
}
while(m--){
    long long c=a.top()/2;
    a.pop();
    a.push(c);
}
long long ans=0;
while(!a.empty()){
    ans+=a.top();
    a.pop();
}
cout<<ans;
}