#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())

string s;
string p;


int index = 0;
int parse() {
	if (isalpha(s[index])) {
		return p[s[index++] - 'a'] - '0';
	}
	else {
		int x, y;
		index++;
		char op = s[index++];
		x = parse();
		y = parse();
		index++;
		if (op == '+')return x | y;
		else if (op == '*')return x & y;
		else return x^y;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	

	while(cin>>s>>p){
		int ans = 0;
		index = 0;
		int h = parse();
		rep(x, 10000) {
			p[0] = x / 1 % 10 + '0';
			p[1] = x / 10 % 10 + '0';
			p[2] = x / 100 % 10 + '0';
			p[3] = x / 1000 % 10 + '0';
			index = 0;

			int g = parse();
			if (h == g)ans++;
		}

		cout << h << ' ' << ans << endl;
	}



	return 0;
}
