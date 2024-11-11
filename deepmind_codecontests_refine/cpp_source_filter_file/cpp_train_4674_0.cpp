#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	typedef pair<int,int> pii;
	priority_queue<pii> pq;
	int n, r, l, d, t, x, u = 0;
	scanf("%d%d%d", &n, &r, &l);
	vector<int> s(n + 1), c(n + 1);
	for(int i = 1; i <= n; ++i){
		pq.push(pii(0, ~i));
	}
	for(int i = 0; ; ++i){
		if(i == r){
			t = l;
		}
		else{
			scanf("%d%d%d", &d, &t, &x);
		}
		while(1){
			pii &p = pq.top();
			if(s[~p.second] == p.first){
				c[~p.second] += t - u;
				break;
			}
			pq.pop();
		}
		if(i == r){
			break;
		}
		s[d] += x;
		pq.push(pii(s[d], ~d));
		u = t;
	}
	int ans = max_element(c.begin(), c.end()) - c.begin();
	printf("%d\n", ans);
}