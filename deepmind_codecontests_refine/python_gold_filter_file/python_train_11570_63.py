tc=int(input())
tc+=1
while tc-1:
    tc-=1
    x=int(input())
    if x%2:
        print((x-3)//2+1)
    else:
        print(x//2)
