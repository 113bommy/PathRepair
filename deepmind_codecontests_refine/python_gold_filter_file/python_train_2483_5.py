n,m=map(int,input().split())
lst=[0]*n

for i in range(m):
    a,b=map(int,input().split())
    lst[a-1]+=1
    lst[b-1]+=1

for i in lst:
    print(i)