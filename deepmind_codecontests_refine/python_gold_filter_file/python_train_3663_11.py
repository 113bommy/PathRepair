n=int(input())
a=list(map(int,input().split()))
 
ar=[]
for i in range(n):
	ar.append([a[i],i])
ar.sort(reverse=True)
ans=[0]*n
an=0
for i in range(n):
	ans[i]=ar[i][1]+1
	an=an+ar[i][0]*(i)+1
print(an)
print(*ans)
