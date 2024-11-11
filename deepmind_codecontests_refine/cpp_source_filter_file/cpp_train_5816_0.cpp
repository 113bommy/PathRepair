#include<bits/stdc++.h>
using namespace std;
#define MAX_N 1111
#define pb push_back
#define fi first
#define sc second
typedef pair<ouble,int> P;
int N;
double Xs,Ys,Xt,Yt;
double X[MAX_N],Y[MAX_N],R[MAX_N];
double cost[MAX_N][MAX_N];
double s[MAX_N];
double dis(int i,int j);
int main()
{
	cout.precision(22);cin.precision(22);
	//printf("long double : %d\n", sizeof(long double));
	cin >> Xs >> Ys >> Xt >> Yt;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> X[i] >> Y[i] >> R[i];
	}
	X[N]=Xs;Y[N]=Ys;R[N]=0;
	X[N+1]=Xt;Y[N+1]=Yt;R[N+1]=0;N+=2;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			cost[i][j]=dis(i,j);
			//cout << i << " " << j << " " << cost[i][j] << "\n";
			cost[j][i]=cost[i][j];
		}
	}
	for(int i=0;i<N;i++){
		s[i]=3000000000;
	}
	priority_queue<P,vector<P>,greater<P> >que;
	que.push(P(0,N-2));
	while(!que.empty()){
		P p=que.top();que.pop();
		if(s[p.sc]<=p.fi)continue;
		s[p.sc]=p.fi;
		for(int i=0;i<N;i++){
			if(p.fi+cost[p.sc][i]<s[i]){
				que.push(P(p.fi+cost[p.sc][i],i));
			}
		}
	}
	
	cout << s[N-1] << "\n";
	return 0;
}
double dis(int i,int j){
	double l=sqrt((Y[j]-Y[i])*(Y[j]-Y[i])+(X[j]-X[i])*(X[j]-X[i]));
	l-=(R[i]+R[j]);
	if(l<0)return 0;
	return l;
}
