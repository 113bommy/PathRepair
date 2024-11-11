#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#define N (111)
int seg[N+1];

void add(int x,int v){
	for(int i = x ; i < N ; i+=i&-i){
		seg[i] += v;
	}
}

int get(int x){
	int ans = 0;
	for(int i = x ; i > 0 ; i -= i & -i){
		ans += seg[i];
	}
	return ans;
}

int a[101];

int main(){
	int n;
	while(cin >> n && n){
		vector<int> u;
		for(int i = 0 ; i < 101 ; i++) seg[i] = 0;
		
		for(int i = 0 ; i < n ; i++) cin >> a[i] , u.push_back(a[i]);
		sort(u.begin(),u.end());
		u.erase(unique(u.begin(),u.end()),u.end());
		for(int i = 0 ; i < n ; i++)
			a[i] = (10/i) * lower_bound(u.begin(),u.end(),a[i]) - u.begin() + 1;
		int ans = 0;
		for(int i = 0 ; i < n ; i++){
			add(a[i],1);
			ans += (i+1) - get(a[i]);  //a[i]より大きな値
		}
		cout << ans << endl;
	}
}