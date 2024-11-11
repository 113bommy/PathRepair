#include<iostream>

using namespace std;

int m, n;
int hon[100];

int f(int w) {
	int honIdx = 0;
	for (int i = 0; i < m; i++) {
		int curW = w;
		while (hon[honIdx] <= curW) {
			curW -= hon[honIdx];
			honIdx++;
			if (honIdx == n) return 1;
		}
	}
	return 0;
}

int binsearch_lower_bound() {
  int low = 1; // 範囲の下限
  int high = 1500000 + 1; // 範囲の上限。解はあれば [low, high] の中に存在する
  while (low < high) {
    int mid = (low + high) / 2;  // 中心点（この実装ではオーバーフローしうるので注意）
    int midval = f(mid);  // 中心での値
    
    // 解の範囲を狭める
    if (midval < 1) low = mid + 1;
    else high = mid;
  }
  return low;
}

int main() {
	while(cin >> m >> n, m || n) {
		for (int i = 0; i < n; i++) {
			cin >> hon[i];
		}
		cout << binsearch_lower_bound() << endl;
	}
	return 0;
}