#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <tuple>
#include <iterator>
#include <bitset>
#include <random>
#include <assert.h>
#include <unordered_map>
#include <array>
#include <ctime>

#ifdef _MSC_VER
#include <agents.h>
#endif

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define X first
#define Y second
#define MP make_pair
#define umap unordered_map

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> P;
typedef unsigned int uint;

int s_to_dec(int base, string x){
	int res = 0;
	for (auto c : x){
		res *= base;
		if ('0' <= c && c <= '9') res += c - '0';
		if ('A' <= c && c <= 'Z') res += c - 'A' + 10;
		if ('a' <= c && c <= 'z') res += c - 'a' + 36;
	}
	return res;
}

string s_to_bin(int base, string x){
	int dec = s_to_dec(base, x);
	string res;
	while (dec){
		res += dec & 1 ? '1' : '0';
		dec /= 2;
	}
	return string(REV(res));
}

int split_xor(string s){
	int res = 0;
	int run = 0;
	for (auto c : s){
		if (c == '0'){
			res ^= run;
			run = 0;
		}
		else{
			++run;
		}
	}

	return res^run;
}

int main(){
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int xor = 0;
	rep(i, n){
		int base;
		string s;
		cin >> base >> s;
		xor ^= split_xor(s_to_bin(base, s));
	}
	cout << (xor ? "win" : "lose") << endl;

	return 0;
}