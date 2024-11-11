#include <bits/stdc++.h>
using namespace std;
typedef long long ll
const int inf = 1e9;

ll dat[131072*2], add[131072*2];
int segn = 1;
void init(int n){
	while(segn < n)segn *= 2;
	//for(int i = 0;i < segn*2;i++)dat[i] = inf;
}

void lazy_update(int k, int l, int r){
	dat[k] += add[k]*(r-l);
	add[k*2+1] += add[k];
	add[k*2+2] += add[k];
	add[k] = 0;
}

void update(int a, int b, int x, int k, int l, int r){
	lazy_update(k, l, r);
	if(b <= l || r <= a)return ;
	if(a <= l && r <= b){
		add[k] += x;
		lazy_update(k, l, r);
		return ;
	}
	update(a, b, x, k*2+1, l, (l+r)/2);
	update(a, b, x, k*2+2, (l+r)/2, r);
	dat[k] = dat[k*2+1]+add[k*2+1]+dat[k*2+2]+add[k*2+2];
}

ll get(int a, int b, int k, int l, int r){
	lazy_update(k, l, r);
	if(b <= l || r <= a)return 0;
	if(a <= l && r <= b)return dat[k];
	int vl = get(a, b, k*2+1, l, (l+r)/2);
	int vr = get(a, b, k*2+2, (l+r)/2, r);
	return vl+vr;
}

int main(){
	int n, q, c, s, t, x;
	scanf("%d%d", &n, &q);
	init(n);
	for(int i = 0;i < q;i++){
		scanf("%d", &c);
		if(!c){
			scanf("%d%d%d", &s, &t, &x);
			update(s-1, t, x, 0, 0, segn);
		}else{
			scanf("%d%d", &s, &t);
			ll res = get(s-1, t, 0, 0, segn);
			printf("%lld\n", res);
		}
	}
	return 0;
}
