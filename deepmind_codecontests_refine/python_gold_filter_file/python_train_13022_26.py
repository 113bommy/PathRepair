# import sys 
# sys.stdin=open("input.in",'r')
# sys.stdout=open("outp.out",'w')
n,m=map(int,input().split())
a=[i for i in range(1,m+1)]
for j in range(n):
	l,r=map(int,input().split())
	for x in range(l,r+1):
		if x in a:
			a.remove(x)
	
print(len(a))
print(*a)				 