#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

/*
正面衝突の場合 U-D, L-R
斜め衝突の場合 U-L, L-D, D-R, R-U





*/


int X[1<<18], Y[1<<18];
char D[1<<18];
vector<pair<int, char>> V1[1<<19];
vector<pair<int, char>> V2[1<<19];

int n;

int solve_UR(){
	int Answer = (1 << 24);
	for (int i = 0; i <= 500000; i++) V1[i].clear();
	for (int i = 1; i <= n; i++) {
		if (!(D[i] == 'R' || D[i] == 'U')) continue;
		V1[X[i] + Y[i]].push_back(make_pair(X[i], D[i]));
	}
	for (int i = 0; i <= 500000; i++) {
		sort(V1[i].begin(), V1[i].end());
		for (int j = 0; j < (int)V1[i].size() - 1; j++) {
			if (!(V1[i][j].second == 'R' && V1[i][j + 1].second == 'U')) continue;
			Answer = min(Answer, V1[i][j + 1].first - V1[i][j].first);
		}
	}
	return Answer * 10;
}



int solve_UD(){
	int Answer = (1 << 24);
	for (int i = 0; i <= 500000; i++) V2[i].clear();
	for (int i = 1; i <= N; i++) {
		if (!(D[i] == 'L' || D[i] == 'R')) continue;
		V2[Y[i]].push_back(make_pair(X[i], D[i]));
	}
	for (int i = 0; i <= 500000; i++) {
		sort(V2[i].begin(), V2[i].end());
		for (int j = 0; j < (int)V2[i].size() - 1; j++) {
			if (!(V2[i][j].second == 'R' && V2[i][j + 1].second == 'L')) continue;
			Answer = min(Answer, V2[i][j + 1].first - V2[i][j].first);
		}
	}
	return Answer * 5;
}


void rotate(){
    int tmp;
    rep(i, n){
        tmp = X[i];
        X[i] = 200000-Y[i];
        Y[i] = tmp;
        if (D[i] == 'U') D[i] = 'L';
        else if (D[i] == 'L') D[i] = 'D';
        else if (D[i] == 'D') D[i] = 'R';
        else D[i] = 'U';
    }
    
}


int main()
{
    cin >> n;
    rep(i, n){
        cin >> X[i] >> Y[i] >> D[i];
    }

    int t_time = 2000001;    
    rep(t, 4){
        t_time = min(t_time, solve_UD());
        t_time = min(t_time, solve_UR());
        rotate();
    }

    if (t_time == 2000001) cout << "SAFE" << endl;
    else cout << t_time << endl;

}

