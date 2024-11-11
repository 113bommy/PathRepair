n=int(input())
d=list(map(int,input().split()))
a,b=map(int , input().split())
c=0
for i in range (a-1,b-1):
    c+=d[i]
print(c)