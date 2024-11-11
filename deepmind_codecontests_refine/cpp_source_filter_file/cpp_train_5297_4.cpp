#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int x[10000000]; int n, sum2; long long sum;
int main() {
	while (true) {
		memset(x, 0, sizeof(x));
		cin >> n;
		if (!n) { break; }
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		sort(x, x + n);
		sum2 = 0;
		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += sum2;
			sum2 += a[i];
		}
		cout << sum << endl;
	}
}