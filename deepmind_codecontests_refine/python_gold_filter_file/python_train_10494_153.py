n,a,b,c,d=map(int,input().split())
s=input()
if (c<d):
	if not '##' in s[a-1:d-1]: print('Yes')
	else: print('No')
elif (d<c):
	if (not '##' in s[a-1:c-1])&('...' in s[b-2:d+1]): print('Yes')
	else: print('No')