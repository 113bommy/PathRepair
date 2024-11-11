n,k=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
b.sort(reverse=True)
j=0
for i in range(n):
    if a[i]==0:
        a[i]=b[j]
        j=j+1
s=sorted(a)
if a==s:
    print("No")
else:
    print("Yes")
    