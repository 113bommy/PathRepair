n=int(input())
z=0
for i in range(n):
    x,y=map(int,input().split())
    if y-x>=2:
        z+=1
print(z)