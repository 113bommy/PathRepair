#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

struct dp{
	ll xp; // x+1円払う場合の最小枚数
	ll x0; // x  円払う場合の最小枚数
};

int main(){
	string N;
	cin >> N;
	int len = N.size();
	dp c = {1,0};
	
	for ( int i = 0; i < len; i++ ){
		int x = N[i] - '0';
		
		dp d = c;
		c.x0 = min(d.x0+x  , d.xp+(10-x));
		c.xp = min(d.x0+x+1, d.xp+(10-x-1));
	}
	
	cout << c.x0 << endl;
	
	return 0;
}

