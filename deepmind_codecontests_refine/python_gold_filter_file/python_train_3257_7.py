import sys,math
input=sys.stdin.readline
#print=sys.stdout.write
ri=lambda:int(input())
rl=lambda:list(map(int,input().split()))
rs=lambda:input()
for _ in range(ri()):
    n,w=rl()
    items=rl()
    s=0
    index=[]
    for i in range(n):
        if items[i]>w:
            continue
        if items[i]*2>=w:
            index=[i+1]
            s=items[i]
        elif s+items[i]<=w:
            s+=items[i]
            index.append(i+1)
    if s<math.ceil(w/2):
        print(-1)
        continue
    print(len(index))
    print(*index)
        

    

