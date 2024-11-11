d = int(input())
f = [int(i) for i in input().split()]
g = []
k = 10000000000
op = 0
for i in range(len(f)):
   f[i] = (f[i]-i+d-1)//d
   if k>f[i]:
       k = f[i]
       op = i
print(op+1)
    
       


