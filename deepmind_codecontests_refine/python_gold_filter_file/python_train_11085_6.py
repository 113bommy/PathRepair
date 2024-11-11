a=[0]*4
n=int(input())
b=list(map(int,input().split()))
for i in b:
	a[i]+=1
m=max(a)
print(n-m)

	

