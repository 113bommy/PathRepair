t=int(input())
l=list(map(int,input().split()))
a,b=map(int,input().split())
c=0
d=abs(a-b)
for i in range(d):
    c+=l[i+a-1]
print(c)