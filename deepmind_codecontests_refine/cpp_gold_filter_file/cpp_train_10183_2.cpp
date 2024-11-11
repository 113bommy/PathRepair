#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

int main(){
	int N,K; cin >> N >> K;
	vector<pair<LL,int>> d(N);
	repp(i,0,N) cin >> d[i].second >> d[i].first;
	sort(d.begin(),d.end(),greater<pair<LL,int>>());
	vector<int> b(N+1,0);
	LL x = 0;
	LL s = 0;
	stack<LL> sushi;
	repp(i,0,K){
		s += d[i].first;
		if(b[d[i].second]) sushi.push(d[i].first);
		else {
			b[d[i].second] = 1;
			++x;
		}
	}
	int p = K;
	LL ans = s+x*x;
	while(!sushi.empty()){
		while(p < N && b[d[p].second]) ++p;
		if(p == N) break;
		b[d[p].second] = 1;
		s += d[p].first - sushi.top();
		sushi.pop();
		++x;
		ans = max(ans,s+x*x);
	}
	cout << ans << endl;
	return 0;
}
