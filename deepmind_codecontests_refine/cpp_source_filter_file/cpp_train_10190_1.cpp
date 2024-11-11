#include "bits/stdc++.h"
using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define MP(a, b) make_pair(a, b)
#define F first
#define S second
#define INF 1 << 30

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

int n, m;
vector<pi> s;
int dp[1024];
int main() {
	int nn;
	while ((cin >> nn) && nn) {
		s.clear();
		for (int i = 0; i < nn; ++i) {
			int  a, b, c, d, e, f, g, h,iiii;
			cin >> a >> b >> c >> d >> e >> f >> g >> h>>iiii;
			s.push_back(make_pair(b*60+c+d*60+e+f*60+g+h*60+iiii,a));
		}
		sort(s.begin(),s.end());
		cout<<s[0].second<<endl;
		cout<<s[1].second<<endl;
		cout<<s[nn-2].second<<endl;
	}
	return 0;