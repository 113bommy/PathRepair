#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
int main(){
	int n,m,x,y;cin>>n>>m>>x>>y;
	vector<int> xs(n),ys(m);
	rep(i,n)cin>>xs[i];
	rep(i,m)cin>>ys[i];
	sort(xs.begin(),xs.end());
	sort(ys.begin(),ys.end());
	if(xs[n-1]<ys[0]&&xs[n-1]<y&&x<y&&x<ys[0])cout<<"No ";
	cout<<"War"<<endl;
}