import sys
n=int(input())
a=list(map(int,input().split()))
a.sort()
x=1
for i in range(n):
	x *=a[i]
	if x>10**18:
		print(-1)
		sys.exit()
        
print(x)