t=int(input())
c=0
for _ in range(t):
    x,y,z=map(int,input().split())
    if((x+y+z)>=2):
        c+=1
print(c)