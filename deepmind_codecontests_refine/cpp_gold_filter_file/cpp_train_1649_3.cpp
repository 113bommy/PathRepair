#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N; cin >> N;
	vector<vector<int>> A(2, vector<int>(N));

	for(auto &row: A) for(auto &v: row) cin >> v;

	int sum = A[0][0];
	for(auto &v: A[1]) sum += v;

	int ans = sum;
	for(int i=0; i<N-1; i++){
		sum += A[0][i+1] - A[1][i];
		ans = max(ans, sum);
	}

	cout << ans << endl;

	return 0;
}