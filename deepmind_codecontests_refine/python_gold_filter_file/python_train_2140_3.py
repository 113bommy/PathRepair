n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
b.append(b[m-1])
p=0
r=0
for i in range(n):
	while p+2<len(b) and abs(a[i]-b[p]) >= abs(a[i]-b[p+1]): p+=1
	mn=min(abs(a[i]-b[p]),abs(a[i]-b[p+1]))
	r=max(r,mn)
print(r)