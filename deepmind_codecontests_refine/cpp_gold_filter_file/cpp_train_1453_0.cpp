#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
 
int n, q, root[105000];
long long res;
int marked[105000];
pair<char, int> query[105000];
 
int r(int x){
    if(marked[x])return x;
    return root[x]=r(root[x]);
}
 
int main() {
    while(true){
	scanf("%d%d", &n, &q);
//	cin >> n >> q;
	if(n == 0 && q == 0)return 0;
	res = 0;
	fill(marked, marked + n + 2, 0);
	marked[0] = true;
	for(int i = 1;i < n;i++){
	    cin >> root[i];
	    root[i]--;
	}
	for(int i = 0;i < q;i++){
	    cin >> query[i].first >> query[i].second;
	    query[i].second--;
	    marked[query[i].second] += (query[i].first == 'M');
	}
	for(int i=q;i-- > 0;){
	    if(query[i].first=='M'){
		marked[query[i].second]--;
	    }else{
		res += r(query[i].second) + 1;
	    }
	}
	printf("%lld\n", res);
//	cout << res << endl;
    }
}