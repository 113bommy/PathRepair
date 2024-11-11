#include "bits/stdc++.h"
using namespace std;

int main() {
	int p, q, r;
	cin >> p >> q >> r;
	cout << min(p + q, p + r, q + r) << endl;
}