n,t = map(int,input().split())
l = list(map(int,input().split()))
g = 0
for x in l:
    tem = max(l)-x
    g +=tem
if (t-g) >= 0:
    for x in l:
        c = ((t-g)/n)+max(l)
        print("{0:.6f}".format(c-x))
else: print(-1)