haz=list(map(int,input().split()))
want=list(map(int,input().split()))
stash=0
for x,y in zip(haz,want):
    if x>y:
        stash+=(x-y)//2
need=0
for x,y in zip(haz,want):
    if x<y:
        need+=y-x
if stash>=need:
    print("Yes")
else:
    print("No")
