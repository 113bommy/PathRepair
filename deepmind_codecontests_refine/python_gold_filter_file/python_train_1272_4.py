
n=int(input())
a=list(map(int,input().split()))
a.sort()
a=a[::-1]
k=0
m=0
l1=[0]*n
l1[0]=a[0]
l2=[0]*n
l2[n-1]=a[n-1]
for i in range(1,n):
   l1[i]=l1[i-1]|a[i]
   l2[n-1-i]=l2[n-i]|a[n-i-1]
for i in range(n):
    s=0
    if i>0:
        s=s|l1[i-1]
    if i<n-1:
        s=s|l2[i+1]
    s=(a[i]|s) - s
    if m<s:
        m=s
        k=i
a[0],a[k]=a[k],a[0]
print(*a)