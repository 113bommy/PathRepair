n=int(input())
l=list(map(int,input().split()))
c=0
for i in l:
    if i==1:
        c+=1
if c>=1:
    print("HARD")
else:
    print("EASY")
