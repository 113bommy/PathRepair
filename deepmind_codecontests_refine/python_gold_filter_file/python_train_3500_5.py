a,b = map(int,input().split())
c = list(map(int,input().split()))
if b == 1:
    print(min(c))
elif b >= 3:
    print(max(c))

else:
    print(max(c[0],c[-1]))
