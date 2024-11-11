n=int(input())
v=list(map(int,input().split()))[:n]
c=0
for i in v:
    if i==1:
        c+=1
if c>=1:
    print("HARD")
else:
    print("EASY")