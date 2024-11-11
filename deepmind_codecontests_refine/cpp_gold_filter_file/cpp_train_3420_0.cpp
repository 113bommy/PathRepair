#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=n-1;i>=(0);i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int N;
string s[10010];
string t;
int main(void){
	cin >> N;
	rep(i, N)cin >> s[i];
	cin >> t;
	string tmp = t;
	while(t.size() < 20){
		t += 'A';
	}

	int mae = 0, usi = 0;
	rep(k, N){
		string d = s[k];
		bool fmae = false, fusi = false;

		if(d != tmp){
			rep(i, t.size()){
				if(d[i] != '?' && d[i] < t[i]){
					fmae = true;
					break;
				}else if(d[i] != '?' && d[i] > t[i]){
					fusi = true;
					break;
				}else if(d[i] == '?' && t[i] != 'a' && t[i] != 'z'){
					// printf("k\n");
					fmae = true; fusi = true;
					break;
				}else if(d[i] == '?' && t[i] != 'z'){
					fusi = true;
				}else if(d[i] == '?' && t[i] != 'a'){
					fmae = true;
				}
			}
		}else{
			fmae = true; fusi = true;
		}

		if(fmae) mae++;
		if(fusi) usi++;
	}

	// printf("%d %d\n", mae, usi);
	int r = mae + 1;
	int l = N - usi + 1;
	// printf("%d\n", r - l);
	reps(i, l, r + 1){
		if(i != r)printf("%d ", i);
		else printf("%d\n", i);
	}
	return 0;
}