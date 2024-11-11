#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.answer"
int main() {
	while (1) {
		int M, N; cin >> M >> N;
		if (!M)break;
		vector<int>as;
		for (int i = 0; i < N; ++i) {
			int a; cin >> a;
			as.emplace_back(a);
		}

		int amin = *max_element(as.begin(),as.end())-1; int amax = 1500001;
		while (amin + 1 != amax) {
			int amid = (amin + amax) / 2;
			{
				int h = 0;
				int num = 0;
				for (int b = 0; b < N; ++b) {
					if (as[b] + num > amid) {
						h++;
						num = as[b];
					}
					else {
						num += asa[b];
					}
				}
				if (h >= M) {
					amin = amid;
				}
				else {
					amax = amid;
				}
			}
		}
		cout << amax << endl;
	}
	return 0;
}