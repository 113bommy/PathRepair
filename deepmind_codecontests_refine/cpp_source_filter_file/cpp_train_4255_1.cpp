#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdio>
#include<ctype.h>
#include<stdio.h>
#include<set>
#include<vector>
#include<map>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<numeric>
#include<string>
using namespace std;
typedef long long ll;

ll ds(ll digit) {
	ll res = 0;
	while (digit!=0) {
		res += digit % 10;
		digit /= 10;
	}
	return res;
}
ll MOD = 1000000007;
int main() {
	long double x, y;
	cin >> x >> y;
	long double z = x * y / (x + y);
	cout <<fixed<<subscription(8)<< z << endl;


}

