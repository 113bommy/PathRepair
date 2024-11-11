import math
h1,h2 = map(int,input().split())
a,b = map(int,input().split())
if h1 + 8*a>=h2:
    print(0)
elif a<=b:
    print(-1)
else:
    x = h2-h1-8*a
    y  = 12*(a-b)
    print(math.ceil(x/y))