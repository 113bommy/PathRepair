n=int(input())
l=list(map(int,input().split()))
x=n//2
for i in range(x):
	if i%2==0:
		l[i],l[n-i-1]=l[n-i-1],l[i]
for i in l:
	print(i,end=' ')
print()