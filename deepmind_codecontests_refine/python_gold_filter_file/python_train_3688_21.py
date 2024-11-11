n=int(input())
l=list(map(int,input().split()))
a,b=map(int,input().split())
c=0
for i in range(a,b):
    c+=l[i-1]
print(c)