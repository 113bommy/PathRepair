b=int(input())
g=int(input())
n=int(input())

ansar=0

if(b>=n and g>=n):
    ansar=n+1
elif(b>=n and g<n):
    ansar=g+1
elif(g>=n and b<n):
    ansar=b+1
else:
    ansar=b+g-n+1

print(ansar)
    