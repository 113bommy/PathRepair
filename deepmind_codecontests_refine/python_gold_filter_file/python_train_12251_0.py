import sys
input=sys.stdin.readline
class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
  
    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
  
    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i
n=int(input())
a=list(map(int,input().split()))
bi=Bit(n+1)
c=0
for i,x in enumerate(a):
    bi.add(x,1)
    c+=i+1-bi.sum(x)
if c%2==n%2:
    print("Petr")
else:
    print("Um_nik")