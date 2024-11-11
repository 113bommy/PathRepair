#include<bits//stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
typedef long long ll;
ll n, m, k, y, x, d, w = -1, num, sum, ans = INF; string s;
vector<vector<pair<int,int>>> Gragh;
int main(void) {
	cin >> n;
	for(int i = 0;i*(i-1)/2 <= n;i++)  {
		if (i * (i - 1) / 2 == n) {
			w = i;
			break;
		}
	}if (w == -1) cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		vector<vector<int>> S(w);
		num = 1;
		rep(i, w) {
			for (int j = i + 1; j < w; j++) {
				S[i].push_back(num);
				S[j].push_back(num);
				num++;
			}
		}
		cout << w << endl;
		rep(i, w) {
			cout << S[i].size();
			rep(j, S[i].size()) cout << ' ' << S[i][j];
			cout << endl;
		}
	}
}