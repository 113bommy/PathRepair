include<iostream>
#include<cstdlib>
#define MAX 10

using namespace std;

struct datum {
	char name;
	int win;
	int lose;
};

datum data[MAX];

int compare ( const void * a, const void * b ) {
	const datum x = *((datum*)a);
	const datum y = *((datum*)b);

	if ( x.win == y.win )
		return x.lose - y.lose;
	return y.win - x.win;
}

int main () {

	while ( true ) {
		int n;
		cin >> n;
		if ( n == 0 )
			break;
		for ( int i=0; i<n; i++ ) {
			cin >> data[i].name;
			int win, lose;
			win = 0;
			lose = 0;
			int now;
			for ( int j=0; j<n-1; j++ ) {
				cin >> now ;
				if ( now == 0 )
					win++;
				if ( now == 1 )
					lose++;
			}
			data[i].win = win;
			data[i].lose = lose;
		}

		qsort ( data, n, sizeof(datum), compare);

		for ( int i=0; i<n; i++ ) {
			cout << data[i].name << endl;
		}
	}
}