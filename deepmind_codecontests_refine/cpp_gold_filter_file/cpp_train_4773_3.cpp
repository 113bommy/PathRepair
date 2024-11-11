#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> out[200010];
int in[200010];
int cycle[200010];
int grundy[200010];
int st = -1;
const int CYCLE = 42;

int dfs(int x) {
	cycle[x] = 1;
	for(int i : out[x]) {
		if(cycle[i] == 1) {
			st = i;
			cycle[x] = CYCLE;
			return CYCLE;
		}
		else if(cycle[i] == 0) {
			if(dfs(i) == CYCLE) {
				cycle[x] = CYCLE;
				if(x == st) return 0;
				else return CYCLE;
			}
		}
	}
	cycle[x] = 2;
	return 0;
}

int getgrundy(int x) {
	set<int> s;
	for(int i : out[x])
		if(cycle[i] != CYCLE)
			s.insert(getgrundy(i));
	int ans = 0;
	auto it = s.begin();
	while(it != s.end()) {
		if(*it == ans) {
			++ans;
			++it;
		}
		else return grundy[x] = ans;
	}
	return grundy[x] = ans;
}

bool chk(int x, int val, int res) {
	if(x == st) return res == val;
	int nxt = -1;
	for(int i : out[x]) {
		if(cycle[i] == CYCLE) {
			nxt = i;
		}
	}
	return chk(nxt, grundy[nxt] + (grundy[nxt] == val), res);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	memset(cycle, 0, sizeof cycle);
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		--x;
		out[x].push_back(i);
		in[i] = x;
		if(x < i and in[x] == i) {
			st = i;
			cycle[x] = cycle[i] = CYCLE;
		}
	}
	for(int i = 0; st == -1 and i < n; ++i) if(cycle[i] == 0) dfs(i);
	for(int i = 0; i < n; ++i) if(cycle[i] == CYCLE) getgrundy(i);
	int nxt;
	for(int i : out[st]) {
		if(cycle[i] == CYCLE) {
			nxt = i;
		}
	}
	if(st == nxt or chk(nxt, grundy[nxt] + (grundy[st] == grundy[nxt]), grundy[st])) cout << "POSSIBLE" << endl;
	else if (chk(nxt, grundy[nxt] + ((grundy[st] + 1) == grundy[nxt]), grundy[st] + 1)) cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;

}
