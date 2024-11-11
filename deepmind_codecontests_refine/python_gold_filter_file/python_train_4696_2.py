import sys
from fractions import gcd

line1 = sys.stdin.readline().strip().split()
arr = []
for i in line1:
   arr.append(int(i))
a = arr[0]
b = arr[1]
x = arr[2]
y = arr[3]
g = gcd(x,y)
#print(g)
x /= g;
y /= g;
#print(x, y)
print(min(int(a/x), int(b/y)))
   
