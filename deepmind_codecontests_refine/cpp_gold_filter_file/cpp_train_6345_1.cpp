#include<iostream>
#include<map>
#include<algorithm>
#define M 20000
#define N 20001
using namespace std;
struct data{
	int t,s,d;
	bool operator<(const data &c)const{
		return t < c.t;
	}
};
int main(){
	while(true){
		int n,m;
		int ans=0;
		bool infected[N]={false,};
		data datas[M];
		scanf("%d%d", &n, &m);
		if(n==0&&m==0)
			break;
		for(int i=0;i<m;++i){
			scanf("%d%d%d", &datas[i].t, &datas[i].s, &datas[i].d);
		}
		sort(datas,datas+m);
		infected[1]=true;
		for(int i=0;i<m;++i){
			if( infected[datas[i].s] ){
				infected[datas[i].d]=true;
			}
		}
		for(int i=1;i<=n;++i){
			if( infected[i] )++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}