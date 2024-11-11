#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class team
{
	public:

		team(){c=w=l=0;}

		char c;
		int w,l;

		bool operator<(const team& t) const
		{
			return w!=t.w ? w>t.w : l<t.l;
		}
};

int main()
{
	int n,s;
	while(cin >> n, n)
	{
		vector<team> v;

		for(int j=0; j<n; j++)
		{
			team t;
			cin >> t.c;

			for(int i=0; i<n-1; i++)
			{
				cin >> s;
				if(s==0) { t.w++; }
				if(s==1) { t.l++; }
			}
			v.push_back(t);
		}
		stable_sort(v.begin(), v.end());
		for(int i=0; i<v.size(); i++)
		{
			cout << v[i].c << endl;
		}
	}

	return 0;
}