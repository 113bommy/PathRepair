#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
long long int gcd(long long int l, long long int r) {
	assert(l > 0 && r > 0);
	if (l > r)return gcd(r, l);
	else {
		const long long int num = r%l;
		if (num) {
			return gcd(l, num);
		}
		else {
			return l;
		}
	}
}
long long int lca(long long int l, long long int r) {
	return l / gcd(l, r)*r;
}

//  nd/de
class Fruction
{
public:
	long long int nd;
	long long int de;
	void reduct() {
		if (nd) {
			bool ndminus = false;
			if (nd < 0) {
				ndminus = true;
				nd = -nd;
			}

			const long long int agcd(gcd(nd, de));
			de /= agcd;
			nd /= agcd;
			if (ndminus)nd = -nd;
		}
		else {
			de = 1;
		}
	}
	Fruction() :nd(0), de(1) {

	}
	void initialize() {
		if (de < 0) {
			de = -de;
			nd = -nd;
		}
		reduct();
		
	}
	Fruction(const long long int nd_,const long long int de_) 
		:nd(nd_), de(de_) {
		initialize();
	}
	Fruction(const long long int nd_, const Fruction de_) :
		nd(nd_*de_.de), de(de_.nd) {
		initialize();
	}
	Fruction(const Fruction nd_, const long long int de_) :
		nd(nd_.nd), de(nd_.de*de) {
		initialize();
	}
	Fruction(const long long int num):nd(num),de(1) {
	}
	Fruction(const Fruction& f) :de(f.de), nd(f.nd) {

	}
	pair<long long int, Fruction>mixed() {
		long long int num = nd / de;
		return make_pair(num, Fruction(nd - de*num, de));
	}
};
Fruction operator-(const Fruction&f) {
	return Fruction(-f.nd, f.de);
}
Fruction operator+(const Fruction&l, const Fruction&r) {
	long long int nede = lca(l.de, r.de);
	long long int nend = l.nd*(nede / l.de) + r.nd*(nede / r.de);
	return Fruction(nend, nede);
}
Fruction operator-(const Fruction&l, const Fruction&r) {
	return l+(-r);
}
Fruction operator*(const Fruction&l, const Fruction&r) {
	long long int nend = l.nd*r.nd;
	long long int nede = l.de*r.de;
	Fruction nefr(nend, nede);
	nefr.initialize();
	return nefr;
}
Fruction operator*(const Fruction&l, const long long int&r) {
	return l*Fruction(r, 1);
}
Fruction operator*(const long long int &l, const Fruction&r) {
	return Fruction(l, 1)*r;
}
Fruction operator/(const Fruction&l, const Fruction&r) {
	long long int nend = l.nd*r.de;
	long long int nede = l.de*r.nd;
	Fruction nefr(nend, nede);
	nefr.initialize();
	return nefr;
}
Fruction operator/(const Fruction&l, const long long int&r) {
	return l / Fruction(r, 1);
}
Fruction operator/(const long long int&l, const Fruction&r) {
	return Fruction(l,1) / r;
}

bool operator<(const Fruction&l, const Fruction&r) {
	return l.nd*r.de < r.nd*l.de;
}
bool operator<(const Fruction&l, const Fruction&r) {
	return l.nd*r.de <= r.nd*l.de;
}
bool operator==(const Fruction&l, const Fruction&r) {
	return l.nd*r.de == r.nd*l.de;
}
bool operator>(const Fruction&l, const Fruction&r) {
	return l.nd*r.de > r.nd*l.de;
}
bool operator>(const Fruction&l, const Fruction&r) {
	return l.nd*r.de >= r.nd*l.de;
}

int main() {
	while (1) {
		int T, H, M, S; cin >> T >> H >> M >> S;
		if (!T)break;
		int total = T*60*60;
		int ntime = H * 3600 + M * 60 + S;
		if (!T)break;
		Fruction speeds[3];
		speeds[0] = Fruction(1, T * 60 * 60);
		speeds[1] = Fruction(1, 60 * 60);
		speeds[2] = Fruction(1, 60);
		Fruction now[3];
		for (int i = 0; i < 3; ++i) {
			now[i] = Fruction(speeds[i] * ntime);
			now[i] = now[i].mixed().second;
		}
		Fruction ans(1e9,1);
		for (int i = 0; i < 1; ++i) {
			Fruction dspeed = -(speeds[i] + speeds[(i + 1) % 3]) / 2 + speeds[(i + 2) % 3];
			Fruction dkaku = (now[i] + now[(i + 1) % 3]) / 2 - now[(i + 2) % 3];
			if (dspeed < 0) {
				dkaku = -dkaku;
				dspeed = -dspeed;
			}
			for (int j = -49; j < 50; ++j) {
				Fruction nans = (dkaku +  j* Fruction(1, 2)) / dspeed;
				Fruction next[3];
				for (int k = 0; k < 3; ++k) {
					next[k] = now[k] + nans*speeds[k];
					next[k] = next[k].mixed().second;
				}
				bool ok = true;
				for (int k = 0; k < 3; ++k) {
					if (next[k] == next[(k + 1) % 3])ok = false;
				}
				if (nans >= Fruction(0,1)) {
					if (ok) {
						ans = min(ans, nans);
					}
				}
			}
		}
		pair<long long int, Fruction>p(ans.mixed());
		long long int fintime = ntime + p.first;
		fintime %= T * 60 * 60;
		const int nh = fintime / 3600;
		fintime -= nh * 3600;
		const int nm = fintime / 60;
		fintime -= nm * 60;
		Fruction ns(fintime*p.second.de + p.second.nd, p.second.de);
		cout << nh << " " << nm << " " << ns.nd << " " << ns.de << endl;
	}
	return 0;
}