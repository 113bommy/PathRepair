#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define reps(i, n, m) for (int i = (int) (n); i < (int) (m); i++)
#define PB push_back

using ll = long long;

using namespace std;

void init();
void solve();
void dfsl(int);

int main()
{
	init();
	solve();
}

struct person {
	vector<int> v;
	bool f;
};

struct lang {
	vector<int> v;
        bool f;
};

vector<person> p;
vector<lang> l;
int N, M;

void init()
{
	cin >> N >> M;
	rep(i, N) {
		person t;
		t.f = false;
		t.v.resize(0);
		p.PB(t);
	}
	rep(i, M) {
		lang t;
		t.v.resize(0);
                t.f = false;
		l.PB(t);
	}
	rep(i, N) {
		int k;
		cin >> k;
		rep(j, k) {
			int t;
			cin >> t;
			t--;
			p[i].v.PB(t);
			l[t].v.PB(i);
		}
	}
}

void dfsp(int x)
{
	if (p[x].f) return;
	p[x].f = true;
	for (int t : p[x].v) {
		dfsl(t);
	}
}

void dfsl(int x)
{
        if (l[x].f) return;
        l[x].f = true;
	for (int t : l[x].v) {
		dfsp(t);
	}
}

void solve()
{
	dfsp(0);
	rep(i, N) {
		if (!p[i].f) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}
