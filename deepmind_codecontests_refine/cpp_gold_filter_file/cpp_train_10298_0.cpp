#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <functional>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

int parse_impl(string::const_iterator &begin, string::const_iterator end) {
	assert(*begin == '[');
	begin++;
	if (*begin == '[') {
		vector<int> nodes;
		do {
			nodes.push_back(parse_impl(begin, end));
		} while (*begin != ']');
		begin++;
		std::sort(nodes.begin(), nodes.end());
		int min_win = 0;
		for (int i = 0; i < nodes.size() / 2 + 1; i++) {
			min_win += nodes[i];
		}
		return { min_win };
	}
	else {
		int value = 0;
		do {
			value *= 10;
			value += *begin - '0';
			begin++;
		} while (*begin != ']');
		begin++;
		return { value / 2 + 1 };
	}
}

int parse(string line) {
	auto it = line.cbegin();
	return parse_impl(it, line.end());
}

void solve() {
	string line;
	cin >> line;
	cout << parse(line) << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		solve();
	}
}