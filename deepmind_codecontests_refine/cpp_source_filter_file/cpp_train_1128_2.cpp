#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> a(N);
	for (auto& x : a) {
		cin >> x;
	}

	set<int> s;
	int t = 0;
	for (auto x : a) {
		if (x < 3200) {
			s.insert(x / 400);
		}
		else {
			++t;
		}
	}

	cout << max(1u, s.size()) << " " << s.size() + t << endl;
}
