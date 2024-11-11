#include<bits/stdc++.h>
using namespace std;
const long long INF=1e12;
struct edge{int from,to,cost;};
edge es[2000];
long long d[1000];
int V,E;
void shortest_path(int s){
	for(int i=0;i<V;i++)
		d[i]=INF;
	d[s]=0;
	for(int i=0;i<V;i++)
		for(int j=0;j<E;j++){
			edge e=es[j];
			if(d[e.from]!=INF&&d[e.to]>d[e.from]+e.cost)
				d[e.to]=d[e.from]+e.cost;
		}
	}
}
bool find_negative_loop(){
	memset(d,0,sizeof(d));
	for(int i=0;i<2*V;i++){
		for(int j=0;j<E;j++){
			edge e=es[i];
			if(d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				if(i>=V-1&&e.to==V-1)
					return true;
			}
		}
	}
	return false;
}
int main(){
	cin>>V>>E;
	int a,b,c;
	for(int i=0;i<E;i++){
		cin>>a>>b>>c;
		es[i]=(edge){a-1,b-1,-c};
	}
	if(find_negative_loop()){
		cout<<"inf"<<endl;
		return 0;
	}
	shortest_path(0);
	cout<<-d[V-1]<<endl;
}
