include <iostream>
using namespace std;
const int num = 200002, INF = 2000000000;
int a[num], n;
inline long long me(int left, int mid, int right) {
	int long long cnt = 0;
	int n1 = mid - left;
	int n2 = right - mid;
	int l[num / 2], r[num/2];
	l[n1] = r[n2] = INF;
	for (int i = 0; i < n1; i++) 
		l[i] = a[left + i];
	for (int i = 0; i < n2; i++)
		r[i] = a[mid + i];
	int s = 0, t = 0;
	for (int i = left; i < right; i++) {
		if (l[s] > r[t]) {
			a[i] = r[t];
			t++;
			cnt += n1 - s;
		}
		else {
			a[i] = l[s];
			s++;
		}
	}
	return cnt;
}
inline long long ms(int l, int r) {
	long long s1 = 0, s2 = 0, v = 0;
	if (l != r - 1) {
		int m = (l + r) / 2;
		 s1 = ms(l, m);
		 s2 = ms(m, r);
		 v = me(l, m, r);
	}
	return s1 + s2 + v;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}
	long long ans = ms(0, n);
	cout << ans << endl;
	return 0;
}