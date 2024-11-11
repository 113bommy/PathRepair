include<bits/stdc++.h>
using namespace std;
int main() {
	long long K;
	cin >> K;
	
	queue<long long > q;
	for (int i = 1; i <= 9; i++) q.push(i);
	while (!q.empty()) {
		long long x = q.front(); q.pop();
		K--;
		if (K == 0) { cout << x << endl; break; }
		
		for (int y = (x % 10) - 1; y <= (x % 10) + 1; y++) {
			if (y < 0 || y >= 10) continue;
			q.push(x * 10 + (long long)y);
		}
	}
	return 0;
}