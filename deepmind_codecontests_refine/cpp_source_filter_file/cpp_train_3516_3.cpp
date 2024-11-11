#include<iostream>

using namespace std;
const int N = 200010;

int a[N];

int main()
{
    int n;
	cin >> n;
	int x = 0;
    for(int i = 0; i < n; i++)	cin >> a[i], x ^= a[i];
    for(int i = 0; i < n; i++)	cout << x ^ a[i] << ' ';
    return 0;
}