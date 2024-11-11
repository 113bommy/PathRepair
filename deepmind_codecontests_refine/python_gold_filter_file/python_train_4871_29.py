import math
h,w = map(int,input().split())
print(1 if (h==1 or w==1) else math.ceil(h*w/2))
