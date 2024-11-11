#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	int r = a % b;
	return gcd(b, r);

int we(int wl, int wr, int lel, int ler) {
	int ml = wl * lel;
	int mr = wr * ler;
	int bil = mr / gcd(ml, mr);
	int bir = ml / gcd(ml, mr);
	return (wl * bil)+(wr*bir);
}
int main(){
	int n;
	cin >> n;
	while(n!=0){
	vector<int> w(n);
	vector<int> lel(n);
	vector<int> ler(n);
	vector<int> nul(n);
	vector<int> nur(n);
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> lel[i] >> ler[i] >> l >> r;
		l--; r--;
		nul[i] = l; nur[i] = r;
	}
	vector<int> d(n,n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x, y;
			if (nul[j] == -1) {
				x = -1;
			}
			else {
				x = d[nul[j]];
			}
			if (nur[j] == -1) {
				y = -1;
			}
			else {
				y = d[nur[j]];
			}
			d[j]=min(d[j], max(x, y)+1);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (d[j] == i) {
				int wl, wr;
				int l = nul[j];
				int r = nur[j];
				if (l == -1) {
					wl = 1;
				}
				else {
					wl = w[l];
				}
				if (r == -1) {
					wr = 1;
				}
				else {
					wr = w[r];
				}
				w[j] = we(wl, wr, lel[j], ler[j]);
				ans = max(ans, w[j]);
			}
		}
	}
	cout << ans << endl;
	cin >> n;
	}
}

