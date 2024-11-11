n = int(input())
a = [int(i) for i in input().split()]
l = [i for i in range(len(a))]
r = [i for i in range(len(a))]
for i in range(len(a)):
	while l[i]>=1 and a[i]|a[l[i]-1]<=a[i]:
		l[i] = l[l[i]-1]
    
for j in range(len(a)):
	i = len(a)-j-1
	while r[i]<len(a)-1 and a[i]|a[r[i]+1]<=a[i] and a[i]>a[r[i]+1]:
		r[i] = r[r[i]+1]

count=0
for i in range(len(a)):
	x = r[i]-i+1
	y = i-l[i]+1
	count+=x*y-1
print((n*(n-1))//2-count)