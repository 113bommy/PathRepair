t=int(input())
for _ in range(t):
    l,r,d=map(int,input().split())
    if(l>d):
        print(d)
    else:
        print(((r//d)+1)*d)