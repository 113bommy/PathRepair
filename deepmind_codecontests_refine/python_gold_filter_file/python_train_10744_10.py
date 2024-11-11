t=int(input())
for _ in range(t):
    r,g,b=list(map(int,input().split()))
    o=max(r,g,b)
    if o>((r+g+b)-o+1):
        print('No')
    else:
        print('Yes')