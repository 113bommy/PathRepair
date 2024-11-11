#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> P;
typedef pair<int,P> E;
#define M 1000000007
#define all(a) (a).begin(),(a).end()
#define rep(i,n) reps(i,0,n)
#define reps(i,m,n) for(int i=(m);i<(n);i++)
int main(){
  int n,q;cin>>n>>q;
  vector<E> v;
  rep(i,n){
    int a,b,c;cin>>a>>b>>c;
    v.push_back(E(a-c,P(-1,c)));
    v.push_back(E(b-c,P(0,c)));
  }
  rep(i,q){
    int c;cin>>c;
    v.push_back(E(c,P(1,i)));
  }
  sort(all(v));
  multiset<int> m;
  for(auto a:v){
    int x=a.first,y=a.second.first,z=a.second.second;
    if(y==-1)m.insert(z);
    else if(y==0)m.erase(m.lower_bound(z));
    else cout<<(m.empty()?-1:*m.begin())<<endl;
  }
}