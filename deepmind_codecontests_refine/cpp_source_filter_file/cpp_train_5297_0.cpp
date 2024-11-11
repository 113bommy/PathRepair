#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <tuple>
#include <queue>
#include <functional>
using namespace std;
int main() {
	int n;;
	while (cin >> n, n) {
		vector<long long> a(n);
		for (long long &x : a)cin >> x;
		sort(a.begin(), a.end());
		long long sum = 0;
		for (long long &x : a)sum1+=sum,sum+=x;
		//sum = 0;
		//for (long long &x : a)x = (sum += x);
		cout << sum1 << endl;
	}
	return 0;
}