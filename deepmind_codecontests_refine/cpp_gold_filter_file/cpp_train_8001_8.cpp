#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	char sta[210];
	cin.getline(sta, 210);
	string sa = sta;

	transform(sa.begin(), sa.end(), sa.begin(),:: toupper);
	cout << sa << endl;

	return 0;
}