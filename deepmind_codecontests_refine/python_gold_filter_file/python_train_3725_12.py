import math
a,b,H,M=map(int,input().split())
ans=math.sqrt(pow(a,2)+pow(b,2)-2*a*b*math.cos(math.radians(abs(30*H-11*M/2))))
print(ans)