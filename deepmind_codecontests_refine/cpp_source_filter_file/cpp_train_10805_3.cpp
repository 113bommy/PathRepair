#define HAVE_STRUCT_TIMESPEC
#include<bits/stdc++.h>
using namespace std; 
int n;
int a[1007][1007],t[1007],p[1007];
queue<int>q[2];
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)
        for(int j=1;j<n;++j)
            cin>>a[i][j];
	for(int i=1;i<=n;++i)
        q[0].push(i);
	int now=1;
	for(int day=1,tot=n*(n-1)/2;day<=n*(n-1)/2;++day){
		now^=1;
		while(!q[now].empty()){
			int x=q[now].front();
            q[now].pop();
			int y=a[x][++t[x]];
			if(p[y]==x){
				tot--;
				q[1-nex].push(x);
				q[1-nex].push(y);
				p[x]=p[y]=0;
			}
			else 
                p[x]=y;
		}
		if(!tot){
			cout<<day<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
} 