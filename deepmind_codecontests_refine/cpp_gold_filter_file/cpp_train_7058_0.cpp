#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
int n;
cin>>n;
vector<int>a(n),b(n);
for(int i=0;i<n-1;i++){
    cin>>a.at(i)>>b.at(i);
    a.at(i)--;
    b.at(i)--;
}
vector<int> score(n);
for(int i=0;i<n;i++)cin>>score.at(i);
sort(score.begin(),score.end(),greater<int>());
vector<vector<int>> graph(n);
for(int i=0;i<n-1;i++){
    int c=a.at(i),d=b.at(i);
    graph.at(c).push_back(d);
    graph.at(d).push_back(c);
}
vector<int> ans(n,0);
queue<int> Q;
Q.push(0);
int idx=0;
while(!Q.empty()){
    int now=Q.front();
    Q.pop();
    ans.at(now)=score.at(idx);
    idx++;
    for(int i=0;i<graph.at(now).size();i++){
        if(ans.at(graph.at(now).at(i))==0)Q.push(graph.at(now).at(i));
    }
}
ll total=0;
for(int i=1;i<n;i++){
    total+=score.at(i);
}
cout<<total<<endl;
for(int i=0;i<n;i++){
    cout<<ans.at(i)<<endl;
}
}
