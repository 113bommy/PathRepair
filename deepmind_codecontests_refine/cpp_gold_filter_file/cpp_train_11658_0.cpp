#include<iostream>
#include<string>
#include<vector>
using namespace std;
int a[10000], b[10000], cnt; char c;
string S[10000];
vector<int>A;
vector<string>B;
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n * 2; i++) {
		cin >> a[i] >> c >> b[i] >> S[i];
		if (i >= 1 && i % 2 == 0) {
			if ((a[i] * 60 + b[i]) - (a[i - 1] * 60 + b[i - 1]) >= m) {
				B.push_back(S[i]); A.push_back((a[i] * 60 + b[i]) - (a[i - 1] * 60 + b[i - 1]));
			}
		}
	}
	cout << A.size() << endl;
	for (int i = 0; i < A.size(); i++) {
		cout << B[i] << ' ' << A[i] << endl;
	}
}