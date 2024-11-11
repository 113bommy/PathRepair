#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7, MAX = 110;
int n, h[MAX], pw[MAX];
inline int add(int a, int b) {
	return a + b >= mod ? a + b - mod : a + b;
}
inline int sub(int a, int b) {
	return a >= b ? a - b : a - b + mod;
}
inline int mul(int a, int b) {
	return LL(a) * b % mod;
}
int pm(int a, LL b) {
	if (b == 0) return 1;
	if (b & 1) return mul(a, pm(a, b - 1));
	return pm(mul(a, a), b / 2);
}
pair<int, int> solve(int a, int b, int s) {
	if (b - a == 1) {
		int w = pm(2, h[a] - s);
		return make_pair(w, w);
	}
	int m = *min_element(h + a, h + b);
	vector <pair<int, int> > v;
	int i = a;
	while (i < b) {
		int j = i;
    	while (j < b && (h[i] == m) == (h[j] == m))
			j ++;
    	v.push_back(make_pair(i, j));
    	i = j;
	} 
	int fT = 1, fA = 2;
  	for (int i = 0; i < v.size(); i ++) {
		pair<int, int> p = v[i];
	    int x = p.first, y = p.second;
	    if (h[x] != m) {
	    	pair <int,int> g = solve(x, y, m);
	    	fT = mul(fT, add(g.first, g.second));
	    	fA = mul(fA, g.first);
	    } else {
	    	fT = mul(fT, pw[y - x]);
	    }
	}
	fT = sub(fT, fA);
	fA = mul(fA, pm(2, m - s - 1));
	fT = add(fT, fA);
	return make_pair(fA, fT);
}
int main(void) {
	cin >> n;
	//DWORD start_time = GetTickCount();
	for (int i = 0; i < n; i ++)
		cin >> h[i];
	pw[0] = 1;
	for (int i = 0; i < n; i ++)
		pw[i + 1] = mul(pw[i], 2);
	pair <int, int> g = solve(0, n, 0);
	cout << g.second << endl;
	//DWORD end_time = GetTickCount();
	//cout << "Time costed : " << (end_time - start_time)  << ".ms" << endl;
	return 0;
}