#include <iostream>
using namespace std;

int Balls[10];

bool dfs(int i, int R, int L)
{
	if(i == 10) return true;

	if(dfs(i+1, Balls[i], L) && Balls[i] > R) return true;

	if(dfs(i+1, R, Balls[i]) && Balls[i] > L) return true;

	return false;
}

void main()
{
	int n;

	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<10; j++)
			cin >> Balls[j];

		if(dfs(0, 0, 0)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}