#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

bitset<10010> ok[2010];
int n, k;
string s[2010];
char ans[10010];
vector<int> pts;

int fail[10010];
int self[10010];
int match[10010];

int an;

int main()
{
	cin>>n>>k;
	for(int i=1; i<=n; ++i) cin>>s[i];
	ok[n+1][0]=1;
	for(int i=n; 1<=i; --i) ok[i] = ok[i+1] | (ok[i+1]<<(s[i].length()));
	pts.pb(0);
	for(int i=1; i<=n; ++i){
		const char* p = s[i].c_str();
		int l = s[i].length();
		
		fill(fail, fail+l, 0);
		fill(self, self+l, 0);
		fill(match, match+an+1, 0);
		
		for(int i=1; i<l; ++i){
			int j=fail[i-1];
			while(j && p[j] != p[i]) j=fail[j-1];
			if(p[j] == p[i]) ++j;
			fail[i]=j;
			if(j) self[i-j+1]=max(self[i-j+1], j);
		}
		for(int i=0; i<l; ++i){
			int& m=self[i];
			while(m<l-i && p[m]==p[i+m]) ++m;
			if(m){
				int& t=self[i+m-fail[m-1]];
				t=max(t, fail[m-1]);
			}
		}
		
		for(int i=0, ml=0; i<ans; ++i){
			while(ml && p[ml] != ans[i]) ml=fail[ml-1];
			if(p[ml] == ans[i]) ++ml;
			if(ml) match[i-ml+1] = max(match[i-ml+1], ml);
		}
		
		for(int i=0; i<an; ++i){
			int& m=match[i];
			while(m<l && ans[i+m] == p[m]) ++m;
			if(m>=2){
				int& t=match[i+m-fail[m-1]];
				t=max(t, fail[m-1]);
			}
		}
		
		int cmp = -1;
		for(int st:pts){
			if(k<(st+l) || !ok[i+1][k-(st+l)]) continue;
			if(cmp == -1){
				if(match[st]<l && (st+match[st]==an || p[match[st]]<ans[st+match[st]])){
					cmp = st;
				}
			} else if(cmp+l <= st) break;
			else {
				int sa = st-cmp;
				if(match[cmp] >= sa){
					if(self[sa] == l-sa || p[self[sa]]<p[sa+self[sa]]) cmp=st;
				}
			}
		}
		
		int lm = an;
		if(cmp != -1){
			lm = cmp + match[cmp], an = cmp+l;
			for(int i=0; i<l; ++i) ans[cmp+i]=p[i]; ans[an]=0;
		}
		vector<int> nv;
		for(int st:pts){
			if(k<(st+l) || !ok[i+1][k-(st+l)]) continue;
			if((match[st]==l && (cmp==-1 || st+match[st]<=cmp)) || match[st]>=cmp-st && self[cmp-st]==l-(cmp-st)){
				nv.pb(st+l);
			}
		}
		vector<int> fn;
		for(int i=0,j=0; i<pts.size() || j<nv.size();){
			if(j==nv.size() || (i<pts.size() && j<nv.size() && pts[i]<nv[j])){
				if(pts[i]<=lm){
					if(fn.empty() || fn.back() != pts[i])
						fn.pb(pts[i]);
				}
				++i;
			} else {
				if(fn.empty() || fn.back() != nv[j]) fn.pb(nv[j]);
				++j;
			}
		}
		swap(pts, fn);
	}
	puts(ans);
	return 0;
}
