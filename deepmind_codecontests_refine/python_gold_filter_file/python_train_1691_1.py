import math
LI = lambda: list(map(int,input().split()))
MI = lambda: map(int,input().split())
yes = lambda: print("YES")
no = lambda: print("NO")
I = lambda: list(input())
J = lambda x: "".join(x)
II = lambda: int(input())
SI = lambda: input()
#---khan17---template
t = II()
for q in range(t):
	n = II()
	p = LI()
	a = [0]*(n+1)
	lastTem = n-1
	lastItem = 1
	ans = True
	for i in range(n):
		a[p[i]] = i
	for i in range(2,n+1):
		if a[i]-1!=a[i-1]:
			if a[i-1]!=lastTem:
				ans = False
				break
			else:
				aa = lastTem
				lastTem = a[lastItem]-1
				lastItem  = p[aa]+1
	if ans == True:
		print("Yes")
	else:
		print("No")


