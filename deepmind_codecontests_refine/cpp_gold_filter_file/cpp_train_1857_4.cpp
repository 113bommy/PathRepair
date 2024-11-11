#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	int N, i, ans=0;
	cin >> N;
	int a[N];
	for(i=0; i<N; i++) cin >> a[i];
	sort(a, a+N);
	i=N-1;
	for(i=N-1; i>=0; i-=2){
		ans += a[i];
		if(i==0) break;
		ans -= a[i-1];
	}
	cout << ans ;
}