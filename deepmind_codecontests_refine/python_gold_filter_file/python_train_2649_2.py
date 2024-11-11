a,b=map(int,input().split())
r=list(map(int,input().split()))
r.sort()
s=0
for i in range(len(r)):
	s+=r[i]*max(1,b-i)
print(s)