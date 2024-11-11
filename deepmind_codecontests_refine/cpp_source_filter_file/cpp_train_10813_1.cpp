#include<iostream>
#include<climit>
using namespace std;

#define N 8
static const int cap[N] = {4, 1, 4, 1, 2, 1, 2, 1};

int main(){
    int Q[N];
    while( cin >> Q[0] ){
	for ( int i = 1; i < N; i++ ) cin >> Q[i];

	int min = INT_MAX;
	int minv = INT_MAX;
	int start;

	for ( int s = 0; s < N; s++ ){
	    int sum = 0;
	    for ( int i = 0; i < N; i++ ){
		int rem = Q[i] - cap[(i+s)%N];
		if ( rem > 0 ) sum += rem;
	    }
	    int value = 0;
	    int p = 1;
	    for ( int i= N-1; i >= 0; i-- ){
		value += p * cap[(i+s)%N];
		p *= 10;
	    }

	    if ( sum == min ) {
		if ( value < minv ){
		    min = sum;
		    minv = value;
		    start = s;
		}
	    } else if ( sum < min ){
		min = sum;
		minv = value;
		start = s;
	    }
	}

	int j = 0;
	for ( int i = start; i < N + start; i++ ){
	    if ( j ) cout << " ";
	    cout << cap[i%N];
	    j++;
	}
	cout << endl;
    }
}