#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
//#define int long long
using namespace std;

struct Dice
{
	int c[6];	//??????????????????

	Dice() {}

	//c0:???, c1:??????, c2:???, c3:?\\, c4:???, c5:???
	Dice(int c0, int c1, int c2, int c3, int c4, int c5)
	{
		c[0] = c0; c[1] = c1; c[2] = c2; c[3] = c3; c[4] = c4; c[5] = c5;
	}

	void temae()
	{
		int temp = c[0];
		c[0] = c[3]; c[3] = c[5]; c[5] = c[1];
		c[1] = temp;
	}

	void oku()
	{
		int temp = c[0];
		c[0] = c[1]; c[1] = c[5]; c[5] = c[3];
		c[3] = temp;
	}

	//y????????¢??????
	void y_migi()
	{
		int temp = c[1];
		c[1] = c[4]; c[4] = c[3]; c[3] = c[2];
		c[2] = temp;
	}

	//y????????¢??????
	void y_hidari()
	{
		int temp = c[1];
		c[1] = c[2]; c[2] = c[3]; c[3] = c[4];
		c[4] = temp;
	}

	//z????????¢??????
	void z_migi()
	{
		int temp = c[0];
		c[0] = c[4]; c[4] = c[5]; c[5] = c[2];
		c[2] = temp;
	}

	//z????????¢??????
	void z_hidari()
	{
		int temp = c[0];
		c[0] = c[2]; c[2] = c[5]; c[5] = c[4];
		c[4] = temp;
	}

	//1???????????\?????????????????¢??????2????¨????????????´????????????????\\??????????????°3????\\????????????????????????
	void format()
	{
		if (c[0] == 1) {
			;
		} else if (c[1] == 1) {
			oku();
		} else if (c[2] == 1) {
			z_hidari();
		} else if (c[3] == 1) {
			temae();
		} else if (c[4] == 1) {
			z_migi();
		} else if (c[5] == 1) {
			oku();
			oku();
		}

		if (c[1] == 2)
		{
			y_migi();
			y_migi();
		} else if (c[2] == 2) {
			y_migi();
		} else if (c[4] == 2) {
			y_hidari();
		} else if (c[3] == 2) {
			return;
		} else {
			if (c[1] == 3)
			{
				y_migi();
				y_migi();
			} else if (c[2] == 3) {
				y_migi();
			} else if (c[4] == 3) {
				y_hidari();
			}
		}
	}

	bool operator == (const Dice &d) const {
		Dice td1 = Dice(c[0], c[1], c[2], c[3], c[4], c[5]);
		Dice td2 = d;

		td1.format();
		td2.format();

		rep(i,6)
		{
			if (td1.c[i] != td2.c[i]) return false;
		}
		return true;
	}
};

int n;
map<string, int> c2n;
string color[6];
int cc[6];
Dice d[30];
bool used[30];

signed main()
{
	c2n["Red"] = 1;
	c2n["Yellow"] = 2;
	c2n["Blue"] = 3;
	c2n["Magenta"] = 4;
	c2n["Green"] = 5;
	c2n["Cyan"] = 6;

	while (true)
	{
		cin >> n;
		if (n == 0) break;

		rep(j,n)
		{
			rep(i,6) cin >> color[i];
			cc[0] = c2n[color[0]];
			cc[1] = c2n[color[1]];
			cc[2] = c2n[color[2]];
			cc[3] = c2n[color[4]];
			cc[4] = c2n[color[3]];
			cc[5] = c2n[color[5]];
			d[j] = Dice(cc[0], cc[1], cc[2], cc[3], cc[4], cc[5]);
		}

		rep(i,n) used[i] = false;

		int ans = 0;
		for (int i=0; i<n; i++)
		{
			for (int j=i+1; j<n; j++)
			{
				if (d[i] == d[j] && used[j] == false;)
				{
					ans++;
					used[j] = true;
				}
			}
		}

		cout << ans << endl;
	}
}