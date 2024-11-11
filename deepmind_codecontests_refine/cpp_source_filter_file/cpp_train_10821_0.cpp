#include <map>
#include <cstdio>
using namespace std;
void solve(int T){
	map<pair<int,int>,int> m;
	char cmd[2];
	int n,k;
	for(;T--;){
		scanf("%s%d",cmd,&n);
		if(*cmd=='D'){
			for(auto it=m.begin();it!=m.end();)if(it->second==n)m.erase(it++);else	++it;
		}else if(*cmd=='R'){
			auto it=m.lower_bound(make_pair(n,2000000000));
			if(it==m.begin()){
				puts("-1");
			}else{
				printf("%d\n",--it->first.first<=n&&n<=it->first.second ? it->second : -1);
			}
		}else if(*cmd=='W'){
			int cur=0;
			scanf("%d",&k);
			for(auto it=m.begin();it!=m.end();++it){
				int d=it->first.first-cur;
				if(d>k)d=k;
				if(d)m[make_pair(cur,cur+d-1)]=n;
				k-=d;
				if(k==0)break;
				cur=it->first.second+1;
			}
			if(k)m[make_pair(cur,cur+k-1)]=n;
		}
	}
}
int main(){for(int T;~scanf("%d",&T)&&T;puts(""))solve(T);}