#include <iostream>
using namespace std;

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	int pre;
	cin >> pre;
	long ans = 0;
	for(int i=0; i<n - 1; i++){
		int x;
		cin >> x;
		ans += min ((long)(x - pre) * a, (long)b);
		pre = x;
	}
	cout << ans;
	return 0;
}

