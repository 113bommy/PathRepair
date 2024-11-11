t = int(input())
for i in range(t):
    l,r = map(int,input().split())
    if l==1:
        print(0)
    elif l==2:
        print(r)
    else:
        print(2*r)