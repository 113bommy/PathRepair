#include<bits/stdc++.h>
using namespace std;
const int maxn = 4000;
#define int long long
int a[maxn], p;
int inv[maxn]{1,1};
int po[maxn]{1};
inline int form(int i){return (i % p + p) % p;}
vector<int> operator * (const vector<int> &a, vector<int> b){
	vector<int> res(a.size() + b.size() - 1ul, 0);
	for(int i = 0;i < a.size();++i){
		for(int j = 0;j < b.size();++j){
			res[i+j] = form(res[i+j] + a[i] * b[j]);
		}
	}
	return res;
}
vector<int> fun{0, 1}, r;
int getv(int i){
	int ci = i, res = r[0];
	for(int j = 1;j < r.size();++j){
		res = form(res + ci * r[j]);
		ci = form(ci * i);
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> p;
	for(int i = 0;i < p;++i)cin >> a[i];
	// 
	for(int i = 2;i < p;++i)inv[i] = (p-p/i) * inv[p % i] % p;
	// 
	r.resize(p);	
	r[0] = a[0];
	for(int i = 1;i < p;++i){
		for(int j = 1;j < p;++j)po[j] = form(po[j-1] * i);
		int ls = 0;
		int v = 1;
		for(int j = 0;j < r.size();++j)ls = form(ls + r[j] * po[j]);
		for(int j = 0;j < i;++j){
			v = form(v * form(i-j));
		}
		int sc = form(inv[v] * form(a[i] - ls));
		// cout << v<<" -V " << "target = " << form(a[i]-ls) << '\n';
		for(int i = 0;i < fun.size();++i)r[i] = form(r[i] + sc * fun[i]);
		fun = fun * vector<int>{-i, 1};
	}
	// for(auto j : fun)cout << j << ' ';cout << '\n';
	for(int i = 0;i < p;++i)cout << r[i] << " \n"[i==p-1];
	// for(int i = 0;i < p;++i)assert(getv(i) == a[i]);
}