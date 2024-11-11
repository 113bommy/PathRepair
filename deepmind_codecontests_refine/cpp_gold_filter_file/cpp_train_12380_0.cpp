#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;

const int My_Inf=2147483647;
const long long int My_LInf=9223372036854775807;
int aa[1000000];
bool isprime(long long int a) {
	if (a == 1 || a == 0)return false;
	for (long long int i = 2; i*i <= a; ++i) {
		if ((a%i)) {
		}
		else {
			return false;
		}
	}
	return true;
}
int main() {
	for (int i = 0; i < 1000000; ++i) {
		aa[i] = isprime(i);
	}
	while (1) {
		int m, a, b; cin >> m >> a >> b;
		if (!m)break;

		int ans=0;
		int p;
		int q;

		for (int i = 2; i < sqrt(m)+2; ++i) {
			if (!aa[i])continue;
			for (int j = i; j < m/i+2; ++j) {

				if (i*j <= m&& aa[j]) {
					if (double(a) / b <= double(i) / j + 1e-8) {
						if (ans < i*j) {
							ans = i*j;
							p = i;
							q = j;
						}
					}
				}
			}
		}
		cout << p <<" "<< q << endl;
	}
	return 0;
}