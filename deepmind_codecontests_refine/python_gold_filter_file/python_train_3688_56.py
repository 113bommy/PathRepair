n=int(input())
d=list(map(int,input().split(" ")))
a,b=map(int,input().split(" "))
s=0
for i in range(a-1,b-1):
	s+=d[i]
print(s)