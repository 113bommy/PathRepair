#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; cin >> N; 
	pair<int, int> P[100010]; 
	int A[100010], B[100010]; 
	map<int, int> M; 
	for(int i = 0; i < N; i++){
		cin >> A[i]; P[i].second = A[i]; 
	}
	for(int i = 0; i < N; i++){
		cin >> B[i]; P[i].first = B[i]; 
	}
	sort(A, A+N); sort(B, B+N); 
	sort(P, P+N); 
	for(int i = 0; i < N; i++){
		if(B[i] < A[i]){
			cout << "No" << endl; return 0; 
		}
	}
	for(int i = 0; i < N; i++){
		if(B[i] >= A[i+1]){
			cout << "Yes" << endl; return 0; 
		}
	}
	vector<int> loop; 
	loop.push_back(0); 
	bool used[100010] = {}; 
	used[0] = true; 
	for(int i = 0; i < N; i++) M[A[i]] = i; 
	for(int i = 0; i < N; i++){
		int a = loop.back(); 
		int b = M[P[a].second]; 
		if(used[b]) break; 
		loop.push_back(b); 
		uesd[b] = true; 
	}
	if(loop.size() == (int) N) cout << "No" << endl; 
	else cout << "Yes" << endl; 
}