#include<set>
#include<iostream>
#include<ctime>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<random>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<functional>
#include<string.h>
#include<limits.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
signed main() {
	int a, b; cin >> a >> b;
	cout << a + b + 2 - a*b / gcd(a, b) - 1 < endl;
}