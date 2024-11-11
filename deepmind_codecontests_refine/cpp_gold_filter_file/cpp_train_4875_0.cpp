#include <bits/stdc++.h>
using namespace std;

int main(){
	const int N=1e5+10;
	int n,m;
	int pre=0;int cnt=0;
	cin >>n>>m;
	struct Node{
		int l,r;
		bool operator<(const Node& rhs)const{
			return r<rhs.r;
		}
	}p[N];

	for(int i=0;i<m;i++){
		cin>>p[i].l>>p[i].r;
	}
	
	sort(p,p+m);
	for(int i=0;i<m;i++){
		if(p[i].l>=pre){
			pre=p[i].r;
			cnt++;
		}
	}
	cout <<cnt<<endl;
	return 0;
}