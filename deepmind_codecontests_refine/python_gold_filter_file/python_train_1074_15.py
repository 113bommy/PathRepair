pai=3.1415926536
n=eval(input())
a=list(map(eval,input().split()))
a.sort()
a=a[::-1]
b=0
c=0
for i in range(n):
    b+=a[i]**2*(-1)**c
    c=c^1
print(b*pai)
