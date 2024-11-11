#include<iostream>
using namespace std;
int main() {
	Int p,q,r;
	cin >> p>>q>>r;
	cout << p + q + r - max(p, max(q, r));
}
