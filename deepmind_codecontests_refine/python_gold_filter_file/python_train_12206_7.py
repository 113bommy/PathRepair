n=int(input())
l=list(map(int,input().split()))
d=[]
c=0
s=sum(l)
for i in range(n):
    if(l[i]*n==s):
        d.append(i+1)
        c=c+1
print(c)
print(*d)
