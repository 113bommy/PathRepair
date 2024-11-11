#include <map>
#include <cstdio>
using namespace std;
int main(){for(int T;~scanf("%d",&T)&&T;puts("")){
	map<pair<int,int>,int>m;
	char C[2];
	int n,k;
	for(;T--;){
		scanf("%s%d",C,&n);
		if(*C=='D'){
			for(auto it=m.begin();it!=m.end();)if(it->second==n)m.erase(it++);else	++it;
		}else if(*C=='R'){
			auto it=m.lower_bound(make_pair(n,2000000000));
			printf("%d\n",it==m.begin()||n<(--it)->first.first||it->first.second<n ? -1 : it->second);
		}else if(*C=='W'){
			int c=0;
			scanf("%d",&k);
			for(auto it=m.begin();it!=m.end();++it){
				int d=it->first.first-c;
				if(d>k)d=k;
				if(d)m[make_pair(c,c+d-1)]=n;
				k-=d;
				if(k==0)break;
				c=it->first.second+1;
			}
			if(k)m[make_pair(c,c+k-1)]=n;
		}
	}
}}