def mi():
	return map(int, input().split())

'''
4 4
1010
1101
'''
n,m = mi()
a = list(input())
b = list(input())

pb = [0]*m

if b[0]=='1':
	pb[0] = 1
for i in range(1,m):
	if b[i]=='1':
		pb[i] = 1
	pb[i]+=pb[i-1]

ans = 0
if m>=n:
	for i in range(n):
		if a[i]=='1':
			ans+=(pb[m-n+i]*pow(2,n-i-1,998244353))%998244353
			ans%=998244353
	print (ans%998244353)
else:
	for i in range(n-m,n):
		if a[i]=='1':
			ans+=(pb[i-(n-m)]*pow(2,n-1-i,998244353))%998244353
			ans%=998244353
	print (ans%998244353)
