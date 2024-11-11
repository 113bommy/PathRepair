#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> rate(8, 0);
	int in;
	int over = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> in;
		if(in >= 3200)over++;
		else rate[in / 400]++;
	}

	for(int i = 0; i < 8; i++)if(rate[i] > 0)cnt++;

	cout << max(1, cnt) << ' ' << cnt + over << endl;
}