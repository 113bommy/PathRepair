#awan-ur-rahman
m,b=map(int,input().split())
maxi=0

for y in range(b) :
    x=(b-y)*m
    sum=((x*(x+1))//2)*(y+1) + ((y*(y+1))//2)*(x+1)
    maxi=max(sum,maxi)

print(maxi)