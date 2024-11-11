n=int(input())
c=0
for i in range(0,n):
    x,y=map(int,input().split())
    if y-x>=2:
        c+=1
print(c)
