#include <bits/stdc++.h>
using namespace std;

int N, M, a;
long long sum;
priority_queue<int> pq;

int main() {
    cin >> N >> M;

    for (int i = 0;i < N; i++) {
        cin >> a;
        pq.push(a);
        sum += a;
    }

    for (int i = 0;i < M; i++) {
    	a = pq.top(); pq.pop();
    	sum -= (a * 0.5);
    	pq.push(a/2);
    }

    cout << sum << endl;
}
