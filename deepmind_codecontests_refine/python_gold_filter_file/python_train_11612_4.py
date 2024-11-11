import math
h1,h2=map(int,input().split())
r,f=map(int,input().split())
if h1+r*8>=h2:print(0)
elif f>=r:print(-1)
else:print(math.ceil((h2-h1-8*r)/(12*(r-f))))
