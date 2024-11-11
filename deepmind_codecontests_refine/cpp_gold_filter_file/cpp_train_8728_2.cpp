#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y;

int main() {
	cin >> x >> y;
	if(abs(x - y) > 1) puts("Alice");
	else puts("Brown");
}