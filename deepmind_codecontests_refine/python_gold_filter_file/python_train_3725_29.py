A,B,H,M=map(int,input().split())
import math
print((A**2+B**2-2*A*B*math.cos(math.radians(5.5*M-30*H)))**(1/2))