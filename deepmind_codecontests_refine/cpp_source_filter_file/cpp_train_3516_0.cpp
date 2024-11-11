#include<iostream>

using namespace std;
const int N = 200010;

int a[N];

int main()
{
    int n;
	cin >> n;
	int xor = 0;
    for(int i = 0; i < n; i++)	cin >> a[i], xor ^= a[i];
    for(int i = 0; i < n; i++)	cout << (xor ^ a[i]) << ' ';
    return 0;
}