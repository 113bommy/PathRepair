#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int silly_sort(vector<int> v, int n){
	vector<pair<int, int> > temp(n);
	for (int i = 0; i < n; i++){
		temp[i].first = v[i];
		temp[i].second = i;
	}
	sort(temp.begin(), temp.end());

	int cost = 0, s = temp[0].first;
	for (int i = 0; i < n; i++){
		int j = temp[i].second;
		if (j != i && j >= 0){
			int n = 1, amin, sum;
			amin = sum = temp[i].first;
			while (j != i){
				int next = temp[j].second;
				sum += temp[j].first;
				n++;
				temp[j].second = -1;
				j = next;
			}
			cost += min(sum + (n - 2) * amin, sum + amin + (n + 1) * s);
		}
	}
	return cost;
}

void main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	cout << silly_sort(v, n) << endl;
}