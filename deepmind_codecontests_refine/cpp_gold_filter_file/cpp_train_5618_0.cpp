 
#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using vs=vector<string>;
using msi=map<string,int>;
using mii=map<int,int>;
using pii=pair<int,int>;
using vlai=valarray<int>;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
struct UnionFind{
    int n;
    set<int> dame;
    vi p;
    vi use;
    UnionFind(int N):n(N){
        p.resize(n);
        use.resize(n);
    	iota(all(p),0);
    	rep(i,n){
    	    int tmp;
    	    cin>>tmp;
    	    unite(i,tmp+i);
    	}
    }
    void unite(int a, int b){int c=root(a),d=root(b); if(c!=d) p[c]=d; else if(a!=b) dame.insert(root(a));}
    int root(int a){return p[a]=(p[a]==a?a:root(p[a]));}
    bool same(int a, int b){return root(a)==root(b);}
    void useable(){
        set<int> tmp;
        for(auto i :dame)tmp.insert(root(i));
        dame=tmp;
        rep(i,n){
            use[i]=dame.find(root(i))==dame.end();
        }
    }
};
int main(){
	int n;
	cin>>n;
	UnionFind uf(n);
	//rep(i,n)cout<<uf.p[i]<<",";cout<<endl;
	uf.useable();
    //for(auto i :uf.use)cout<<i<<",";cout<<endl;
    vi turn(n,-1);
    turn[0]=0;
    queue<int> que;
    que.push(0);
    while(turn[n-1]==-1){
        int c=que.front();que.pop();
        range(d,1,7){
            if(c+d<n && uf.use[c+d] && turn[uf.p[c+d]]==-1){
                que.push(uf.p[c+d]);
                turn[uf.p[c+d]]=turn[c]+1;
            }
        }
    }
    cout<<turn[n-1]<<endl;
	return 0;
}