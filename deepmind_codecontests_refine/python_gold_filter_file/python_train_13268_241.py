n=int(input())
ctr=0
for i in range(n):
    x,y=map(int,input().split())
    if y-x>=2:
        ctr+=1
print(ctr)