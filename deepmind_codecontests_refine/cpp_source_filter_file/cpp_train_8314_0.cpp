#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
const int inf=1e9;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m),n){
		vvi in(n,vi(n));
		vvi pic(m,vi(m));
		rep(i,n)rep(j,n)scanf("%d",&in[i][j]);
		rep(i,m)rep(j,m)scanf("%d",&pic[i][j]);
		pii out(inf,inf);
		int N=n-m+1,M=n-m+1;
		rep(e,4){
			rep(i,n-m+1)rep(j,n-m+1){
				pii t(inf,inf);
				rep(k,m)rep(l,m)
					if(pic[k][l]!=-1){
						if(in[i+k][j+l]!=pic[k][l])goto en;
						t=min(t,pii(i+k,j+l));
					}
				out=min(out,t);
				N=out.first;
				M=out.second;
				goto end;
				en:;
				if(i==N&&j==M)goto end;
			}
			end:;
			if(i==3)break;
			vvi tmp=pic;
			rep(i,m)rep(j,m)pic[i][j]=tmp[j][m-i-1];
		}
		if(out.first==inf)cout<<"NA"<<endl;
		else cout<<out.second+1<<" "<<out.first+1<<endl;
	}
}