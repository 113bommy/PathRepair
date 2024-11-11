#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define reps(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reps(i,0,n)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int INF = 1001001001;
const double EPS = 1e-10;

int main()
{
	int n;
	while(scanf("%d%*c", &n), n){
		char line[2048];
		map<string, int> dict;
		rep(i, n){
			fgets(line, sizeof(line), stdin);
			stringstream sstr(line);
			for(string word; sstr >> word;)
				dict[word]--;
		}
		
		vector<pair<int, string> > a;
		scanf("%s", line);
		for(map<string, int>::iterator itr=dict.begin(); itr!=dict.end(); ++itr){
			if(itr->first[0] == line[0])
				a.push_back(make_pair(itr->second, itr->first));
		}
		if(a.empty())
			puts("NA");
		else{
			sort(a.begin(), a.end());
			rep(i, min(5, (int)a.size()))
				printf("%s%s", i ? " " : "", a[i].second.c_str());
			puts("");
		}
	}
	return 0;
}