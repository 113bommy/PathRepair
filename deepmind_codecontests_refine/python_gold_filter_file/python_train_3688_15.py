n=int(input())
a=list(map(int,input().split()))
c,b=map(int,input().split())
s=0
for i in range(c-1,b-1):
	s+=a[i]
print(s)