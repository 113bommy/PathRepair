include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);++i)
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;

	vector<string> a(h);
	rep(i,h) {
		cin >> a[i];
	}

	vector<bool> row(h, false);
	vector<bool> column(w, false);

	rep(i,h){
		rep(j,w){
			if (a[i][j] == '#') {
				row[i] = true;
				column[j] = true;
			}
		}
	}

	rep(i,h) {
		if (row[i] == true) {
			rep(j,w) {
				if (column[j] == true) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}