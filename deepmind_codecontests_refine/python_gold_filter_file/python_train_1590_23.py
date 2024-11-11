import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int,input().split()))
a.sort()
c=1
b=[]
e=0
for i in range(1,10**9+2):
    s=0
    for j in range(len(a)):
        if i**j>10**10:
            e=1
            break
        s+=abs(i**j-a[j])
    if e==0:
        b.append(s)
    if e==1:
        break
print(min(b))