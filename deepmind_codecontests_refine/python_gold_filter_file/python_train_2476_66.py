a,b,c,d = map(int,input().split())
import math
print("Yes" if math.ceil(a/d) >= math.ceil(c/b) else "No")