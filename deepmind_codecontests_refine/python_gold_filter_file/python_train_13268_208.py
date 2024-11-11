n=int(input())
count=0
for i in range(1,n+1):
    x,y=map(int,input().split())
    if (y-x)>=2:
        count=count+1
print(count)