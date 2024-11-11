#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int next[26][210000];
int best[210000];
int bestl[210000];
int main(){
	string a;
	cin >> a;
	int n = a.size();
	for(int c = 0; c < 26; c++){
		next[c][n] = n;
		for(int i = n-1; i >= 0; i--){
			next[c][i] = next[c][i+1];
			if(a[i] - 'a' == c) next[c][i] = i;
		}
	}
	best[n+1] = 0;
	for(int i = n; i >= 0; i--){
		best[i] = 110000000;
		bestl[i] = -1;
		for(int c = 0; c < 26; c++){
			if(best[next[c][i] + 1] + 1 < best[i]){
				bestl[i] = c;
				best[i] = best[next[c][i] + 1] + 1;
			}
		}
	}
	int r = 0;
	while(r < n){
		if(bestl[r] == -1){
			r++;
		} else {
			cout << (char)(bestl[r] + 'a');
			r = next[bestl[r]][r] + 1;
		}
	}
}
