#include <vector>
#include <map>
#include <string>
#include <tuple>

using namespace std;

int N;
char S[50];

map<tuple<int, int, string>, long long> memo;
long long f(int L, int R, string s)
{
	if(s.size() > R-L) 	return 0;
	if(L==R) 			return s.empty();

	auto e = tuple<int, int, string>(L, R, s);
	if(memo.count(e)) 	return memo[e];

	long long v = 0;
	if(!s.empty())
	{
		if(S[L] == s.back())
			v += f(L+1, R, s.substr(0,s.size()-1));
		for(int i=L+1; i<R;++i)
			if(S[L] == S[i])
				v += f(L+1,i,string(S+i+1,S+R)+s);
	}
	else
	{
		for(int i=L+1; i<R;++i)
			if(S[L] == S[i])
				v += 2*f(L+1,i,string(S+i+1,S+R));
	}
	return memo[e]=v;
}


int main() {
	scanf("%d", &N);
	scanf("%s", S);
	printf("%lld\n", f(0,2*N,string()));
}