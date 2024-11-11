#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
 
int main() {
	
	uint N, M;
	cin >> N >> M;
	
	vector<pair<pair<uint, uint>, uint>> LRC(M);
	uint l, r, c;
	for(uint i=0; i<M; i++) {
		cin >> l >> r >> c;
		auto p = make_pair(l - 1, r - 1);
		LRC[i] = make_pair(p, c);
	}
	
	sort(LRC.begin(), LRC.end());
	
	vector<ll> d(N, -1);
	d[0] = 0;
	
	l = 0;
	r = 0;
	for(uint i=0; i<M; i++) {
		auto LR = LRC[i].first;
		l = LR.first;
		r = LR.second;
		c = LRC[i].second;
		
		if(d[l] == -1) {
			cout << -1;
			return 0;
		}
		
		ll dj = d[l] + c;
		for(uint j=r; j>l; j--) {
			if(d[j] == -1) {
				d[j] = dj;
			} else if (d[j] <= dj) {
				break;
			} else {
				d[j] = dj;
			}
		}
	}
	
	cout << d[N-1];
	
	return 0;
}