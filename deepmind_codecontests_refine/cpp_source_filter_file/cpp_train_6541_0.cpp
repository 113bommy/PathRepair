# include <cstdio>
int main()
{
	int N , C ;
	int s [100000] , t [100000] , c [100000];
	int sm [200002];
	int tt [200002];
	
	scanf("%d %d" ,&N ,& C );
	for(int i =0;i < N ;i++)	scanf("%d %d %d" ,& s[i] ,&t[i] ,&c[i]);
	for(int i =1;i <= C ;i++)
	{	
		for(int j =0; j <200002; j++) tt[j]=0;
		for(int j =0; j < N ; j++) if (c[j]== i) tt[s[j]*2-1]++, tt[t[j]*2] --;
		for(intj =1; j <200002; j++) tt[j]+= tt[j-1];
		for(intj =0; j <200002; j++) if(tt[j] >0) sm[j]++;
	}
	int mx =0;
	for (int j =0;j <200002;j++) if( mx < sm[j]) mx = sm[j];
	printf ("%d\n" ,mx );

	return 0;
}