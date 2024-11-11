n=int(input())
a=[int(i)for i in input().split()]
b=[int(i)for i in input().split()]
ans=[0]*n
s=set([int(i)for i in range(1,n+1)])
for i in range(n):
	if a[i]==b[i]:
		ans[i]=a[i]
		s.remove(a[i])
for i in range(n):
	if a[i]!=b[i]:
		if a[i] not in s:
			if b[i] in s:
				ans[i]=b[i]
				s.remove(b[i])
	if b[i] not in s:
		if a[i] in s:
			ans[i]=a[i]
			s.remove(a[i])		
j=0
for i in s:
	while  ans[j]!=0:
		j+=1
	ans[j]=i
	j+=1
print(*ans)		



