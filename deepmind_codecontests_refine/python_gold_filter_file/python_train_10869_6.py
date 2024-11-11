n=int(input())
l=[int(x) for x in input().split()]
mn=abs(l[0]-l[-1])
a=len(l)
b=1
for i in range(n-1):
	if abs(l[i]-l[i+1])<mn:
		mn=abs(l[i]-l[i+1])
		a=i+1
		b=i+2
print(a,end=' ')
print(b)