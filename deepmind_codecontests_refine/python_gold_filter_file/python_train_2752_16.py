n=int(input())
l=list(map(int,input().split()))
s=0
flag=0
for i in range(n):
	s+=l[i]
	if s<0:
		flag+=1
		s=0
print(flag)