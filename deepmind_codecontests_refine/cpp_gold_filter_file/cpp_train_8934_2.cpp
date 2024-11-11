#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct node{
	ll l, r, d;
	node() : l(0), r(0), d(0) {}
};

node T[202020];
char S[101010];
ll d, k, x;

void insert(ll p, char *S)
{
	if(!*S) return;
	
	if(*S == '0'){
		if(!T[p].l){
			T[p].l = ++k;
			T[k].d = T[p].d + 1;
		}
		insert(T[p].l, S + 1);
	}
	else{
		if(!T[p].r){
			T[p].r = ++k;
			T[k].d = T[p].d + 1;
		}
		insert(T[p].r, S + 1);
	}
}

int main()
{
	ll n, i;
	
	scanf("%lld%lld", &n, &d);
	
	k = 1;
	
	for(; n--; ){
		scanf("%s", S);
		insert(1, S);
	}
	
	for(i=1; i<=k; i++){
		if((T[i].l && !T[i].r) || (!T[i].l && T[i].r)){
			ll t = d - T[i].d;
			x ^= t & -t;
		}
	}
	
	printf("%s\n", x? "Alice" : "Bob");
	
	return 0;
}
