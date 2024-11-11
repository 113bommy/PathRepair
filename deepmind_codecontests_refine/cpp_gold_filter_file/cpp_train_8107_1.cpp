#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;
typedef pair<int, string> P;


void solve()
{
	int n;
	while (scanf("%d\n", &n), n)
	{
		string str;
		map<string, int> Map;
		while (n--)
		{
			getline(cin, str);
			str += " ";
			string s;
			for (int i = 0; i < str.size(); ++i)
			{
				if (str[i] == ' ')
				{
					Map[s]++;
					s.clear();
				}
				else
				{
					s += str[i];
				}
			}
		}
		char c;
		cin >> c;
		vector<P> word;
		map<string, int>::iterator it = Map.begin();
		while (it != Map.end())
		{
			if (it->first[0] == c)
			{
				word.push_back(P(-it->second, it->first));
			}
			++it;
		}
		if (word.empty())
		{
			cout << "NA" << endl;
			continue;
		}
		sort(word.begin(), word.end());
		int displaySize = min((int)word.size(), 5);
		bool isFirst = true;
		for (int i = 0; i < displaySize; ++i)
		{
			if (!isFirst)
			{
				cout << " ";
			}
			isFirst = false;
			cout << word[i].second;
		}
		cout << endl;
	}
}

int main()
{
	solve();
	return(0);
}