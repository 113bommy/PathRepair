#include <bits/stdc++.h>
typedef long long ll;
#define REP(i,a) for(int i = 0; i < (a); i++)
using namespace std;
#define INF 1e9

int dist[200][200];
int N,M,R;

void warshall_floyd(){
	REP(k,N)
		REP(i,N)
			REP(j,N)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main(){
	cin >> N >> M >> R;
	int r[R];
	REP(i,R){
		cin >> r[i];
		r[i]--;
	}
	int a[M],b[M],c[M];
	REP(i,M) cin >> a[i] >> b[i] >> c[i];
	REP(i,M){
		REP(j,M){
			dist[i][j] = INF;
		}
	}
	REP(i,M){
		dist[a[i] - 1][b[i] - 1] = c[i];
		dist[b[i] - 1][a[i] - 1] = c[i];
	}
	warshall_floyd();
	sort(r, r + R);
	int ans = INF;
	do{
		int num = 0;
		REP(i,R - 1) num += dist[r[i]][r[i + 1]];
		ans = min(ans, num);
	}while(next_permutation(r, r + R));
	cout << min << endl;
}