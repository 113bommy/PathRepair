#include<iostream>
#include<math.h>
using namespace std;
int n, m, q;
int a[52], b[52], c[52], d[52];
int ans = 0;
int seq[11];

dfs(int len, int cur){
	if(len == n){
		int sum = 0;
		for(int i = 0; i<q; i++){
			if(seq[b[i]-1] - seq[a[i]-1] == c[i]){
				sum += d[i];
			} 
		}
		ans = max(ans, sum);
		return;
	}
	else{
		seq[len] = cur;
		for(int i = cur; i<=m; i++){
			dfs(len+1, i);
		}
	}
}

int main(){
	cin >> n >> m>> q;
	for(int i = 0; i<q; i++){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	dfs(0,1);
	cout << ans;
	return 0; 
	
} 