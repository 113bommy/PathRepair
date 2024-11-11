n = int(input())
x = [list(map(int,input().split())) for _ in range(n)]
a = 0
b = 0
c = 0
for i in range(n):
  pa = a
  pb = b
  pc = c
  X = x[i]
  a = max(pb,pc)+X[0]
  b = max(pc,pa)+X[1]
  c = max(pa,pb)+X[2]
  
print(max([a,b,c]))
  
