n,k=[int(i) for i in input().split()]
s=[]
a=[]
for i in range(ord('a'),ord('a')+k):
    s+=[chr(i)]
x=(n//k) + 1
for i in range(x):
    a+=s
print(*a[0:n],sep='')

