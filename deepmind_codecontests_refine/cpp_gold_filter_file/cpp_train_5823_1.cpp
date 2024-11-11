#ifndef VS
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#include<string>
#include<assert.h>
#include<math.h>
#include<stdio.h>
#include<ctype.h>
#endif
using namespace std;
typedef long long LL;

#ifdef BTK
#define DEBUG if(1)
#else
#define DEBUG if(0)
#endif

#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l, T r) { bool a = l>r; if (a)l = r; return a; }
template <typename T>inline bool chmax(T &l, T r) { bool a = l<r; if (a)l = r; return a; }

struct input {
	bool success;
	input(){success = true;}
#ifdef BTK
	template<typename T>inline input& operator>>(T& x) {success = !!(cin >> x);return *this;}
#else
	inline input& operator>>(LL& x) {success = (scanf("%lld", &x) != EOF);return *this;}
	inline input& operator>>(int& x) {success = (scanf("%d", &x) != EOF);return *this;}
	inline input& operator>>(char* x) {success = (scanf("%s", x) != EOF);return *this;}
	inline input& operator>>(double& x) {success = (scanf("%llf", &x) != EOF);return *this;}
#endif
}in;

const char space = ' ';
const char ln = '\n';
struct output {
#ifdef BTK
	template<typename T>inline output& operator<<(T x) {cout << x; return (*this);}
	inline void fp(const double x, const char* s) { char buf[20];sprintf(buf, s, x); cout << buf;}
#else
	inline output& operator<<(const int x) { printf("%d", x); return *this;}
	inline output& operator<<(const string x) { printf("%s", x.c_str()); return *this; }
	inline output& operator<<(const char x) { putchar(x); return *this;}
	inline output& operator<<(const LL x) { printf("%lld", x); return *this;}
	inline output& operator<<(const double x) { printf("%lf", x); return *this;}
	inline void fp(const double x, const char* s) {printf(s, x);}
#endif
}out;
typedef vector<int> V;
typedef vector<V> VV;

//KMP
int kmp_search(string& S, string& word, V& table) {
	int n = S.size();
	int m = word.size();
	int i = 0, j = 0;
	for (; j<n&&i<m; i++, j++)
		while (i >= 0 && word[i] != S[j])i = table[i];
	if (i == m)return j - m;
	else return -1;
}


V kmp_table_build(string word) {
	int n = word.size() + 1;
	V table(n, 0);
	table[0] = -1;
	for (int i = 2, j = 0; i<n;) {
		if (word[i - 1] == word[j])table[i++] = ++j;
		else if (j>0)j = table[j];
		else table[i++] = 0;
	}
	return table;
}

int cww(string& S, string& word, V& table) {
	int n = S.size();
	int m = word.size();
	int i = 0, j = 0;
	for (; j < n&&i < m; i++, j++) {
		while (i >= 0 && word[i] != S[j])i = table[i];
	}
	if (i == m)return 0;
	else return m-i;
}

char buf[128];
string s[16];
int len[16][16];
int bit[16][16];
V tables[16];
int dpl[1 << 15][15];
int ts[1 << 15][15];
int stamp[1600];
string ret[1600];
int main() {
	//int T=1;in >> T;REP(_,T){int n;in >> n;
	int n;while(cin>>n,n){
		int cnt = 0;
		REP(i, n) {
			in >> buf;
			s[i] = buf;
			tables[i] = kmp_table_build(s[i]);
		}
		REP(i, n)REP(j, n) {
			int l = cww(s[i],s[j],tables[j]);
			string st = s[i] + s[j].substr(s[j].size() - l, l);
			len[i][j] = l;
			if (i == j)len[i][j] = s[i].size();
			bit[i][j] = 0;
			REP(k, n)if (kmp_search(st, s[k], tables[k]) >= 0)bit[i][j] |= (1 << k);
		}
		REP(i, 1 << n)REP(j, n) {
			dpl[i][j] = 2000;
			ts[i][j] = 0;
		}
		int ret_len = 2000;
		REP(i, n) {
			int b = bit[i][i];
			dpl[b][i] = len[i][i];
		}
		FOR(b, 1, (1 << n)) {
			REP(j, n) {
				if(dpl[b][j] == 2000)continue;
				REP(k, n)if (j != k) {
					int nb = b | bit[j][k];
					if (nb == b)continue;
					int nl = dpl[b][j] + len[j][k];
					chmin(dpl[nb][k], nl);
				}
			}
		}
		REP(i, n)chmin(ret_len, dpl[(1 << n) - 1][i]);
		REP(i, ret_len + 1) {
			ret[i] = "[";
			stamp[i] = 0;
		}
		REP(i, n)if (dpl[(1 << n) - 1][i] != ret_len)dpl[(1 << n)-1][i] = 2000;
		for (int b = (1 << n) - 2; b > 0; b--) {
			REP(j, n) {
				if (dpl[b][j] == 2000)continue;
				bool ok = false;
				REP(k, n)if (j != k) {
					int nb = b | bit[j][k];
					if (nb == b)continue;
					int nl = dpl[b][j] + len[j][k];
					ok |= (nl == dpl[nb][k]);
				}
				if (ok == false)dpl[b][j] = 2000;
			}
		}
		REP(i, n) {
			int b = bit[i][i];
			int l = len[i][i];
			if (l == dpl[b][i]) {
				if (ret[l] == s[i]) {
					ts[b][i] = stamp[l];
				}if (ret[l] > s[i]) {
					stamp[l] = ++cnt;
					ts[b][i] = stamp[l];
					ret[l] = s[i];
				}
			}
		}
		FOR(b, 1, (1 << n)) {
			REP(j, n) {
				int l = dpl[b][j];
				if (l == 2000)continue;
				if (ts[b][j] != stamp[l])continue;
				REP(k, n)if (j != k) {
					int nb = b | bit[j][k];
					if (nb == b)continue;
					int nl = dpl[b][j] + len[j][k];
					if (dpl[nb][k] == nl) {
						string nxt = ret[l] + s[k].substr(s[k].size() - len[j][k], len[j][k]);
						if(ret[nl]==nxt) {
							ts[nb][k] = stamp[nl];
						}
						else if (ret[nl] > nxt) {
							++cnt;
							ts[nb][k] = cnt;
							stamp[nl] = cnt;
							ret[nl] = nxt;
						}
					}
				}
			}
		}
		//out << "Scenario #" << _ + 1 << ":" << ln;
		//out << ret[ret_len] << ln; out << ln;
		out<<(int)ret[ret_len].size() << ln;
	}
	return 0;
}

