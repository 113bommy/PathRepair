#include <iostream>

using namespace std;
int l[200000 + 5],r[200000 + 5],ans[505][505];
int n,m,Q,p,q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> Q;
	for(int i = 1;i <= m;++i){
		cin >> l[i] >> r[i];
		ans[1][r[i]]++;ans[l[i] + 1][r[i]]--;
	}
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= n;++j)
			ans[i][j] += ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
	while(Q--){
		cin >> p >> q;
		cout << ans[p][q] << endl;
	}
	return 0;
}
