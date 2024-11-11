#list(map(int,input().split()))
n = int(input())
x = 0
y = 0
energy  = 0
sol = 0
y = list(map(int,input().split()))
for i in range(0,n,1):
   energy += x - y[i]
   if(energy<0):
      sol += -energy
      energy = 0
   x = y[i];
print(sol)
