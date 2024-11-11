#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#define tout cerr
#else
#define TEST(n) ((void)0)
#define tout cin
#endif

using namespace std;

vector<int> A(1), T;
bitset<5000> D[5001], D2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt","r",stdin));
	TEST(freopen("output.txt","w",stdout));
	TEST(freopen("debug.txt","w",stderr));
	int N, K, ans=0;
	cin>>N>>K;
	for(int i=0;i<N;i++) {
		int a;
		cin>>a;
		if(a<K) A.push_back(a);
	}
	ans=N=A.size(); ans--;
	D[0][0]=D2[0]=1;
	for(int i=1;i<N;i++) D[i]=D[i-1]|(D[i-1]<<A[i]);
	for(int i=N-1;i>0;i--) {
		int k;
		T.clear();
		for(int j=0;j<K;j++) if(D[i-1][j]) T.push_back(j);
		k=T.size()-1;
		for(int j=0;j<K;j++) if(D2[j]) {
			while(k && j+T[k]>=K) k--;
			if(j+T[j]+A[i]>=K) {
				ans--;
				break;
			}
		}
		D2[j]|=D2[j]<<A[i];
	}
	cout<<ans<<'\n';
	return 0;
}
