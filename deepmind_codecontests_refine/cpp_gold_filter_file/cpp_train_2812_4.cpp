#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int n, c;
int main() {
	auto I = [](){int i;cin>>i;return i;};
	set<int> S;
	cin >> n;
	while(n--) S.insert(I());
	cin >> n;
	while(n--)
		if (S.count(I())) ++c;
	cout << c << endl;
	return 0;
}