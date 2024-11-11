#include <bits/stdc++.h>
using namespace std;

int main() {
	int i;
	int j;
	int N;
	int K;
	int q;
	int q11;
	int q22;
	long long p;
	long long p1;
	long long p2;
	long long p3;
	long long p4;
   
	cin >> N >> K;
	int a[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
    sort(a, a + (N), greater<int>());  // a[0:N] を大きい順にソート
  	if (K==1){
		cin >> a[0];
 		p=1000000007;
      	p+=a[0];
		p=p%1000000007;
		cout << p << endl;
      return 0;
    }
	if ((K%2)==1)&&(a[0]<=0)){
		p=1;
		for(int i=0;i<K;i++){
			p*=a[i];
			p=p%1000000007;
		}
		p+=1000000007;
		p=p%1000000007;
		cout << p << endl;
		return 0;
	}
	q=0;
	q11=(K%2);
	q22=N-1;
	for(int i=(K%2);i<K;i++){
		if(a[q11]>-a[q22]) {
			q11++;
		} else {
			q22--;
			q++;
		}
	}
 	if ((q%2)==1){
 		p1=a[q11-1];
		p2=a[q11];
		p3=a[q22];
		p4=a[q22+1];
		if(p1*p2<p3*p4) {
			q11--;
			q22--;
		} else {
			q11++;
			q22++;
		}
	}
  	p=1;
	while (q11 > 0) {
		q11--;
		p*=a[q11];
		p=p%1000000007;
	}
	while (q22 < N-1) {
		q22++;
		p*=a[q22];
		p=p%1000000007;
	}
	p+=1000000007;
	p=p%1000000007;
	cout << p << endl;
	return 0;
}
