# import sys
# sys.stdin=open("input.in","r")
# sys.stdout=open("output.out","w")
n,k= map(int,input().split())
for i in range(k):
	if n%10 == 0:
		n = n/10
	else:
		n = n-1
print(int(n))