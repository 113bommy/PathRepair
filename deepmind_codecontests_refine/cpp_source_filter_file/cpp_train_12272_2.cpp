// AOJ 0135 (http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0135)
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define rep(i,a) for(int i=0;i<(a);++i)

int h;

int main()
{
	scanf( "%d", &h );
	rep( i, h )
	{
		int hh, mm;
		scanf( "%d:%d", &hh, &mm );

		double diff = fabs(hh*30+mm/2.0-mm*6);
		diff = std::min( diff, 360-diff );

		puts( diff<30?"alert":diff<90?"warning":"safe" );
	}

	return 0;
}