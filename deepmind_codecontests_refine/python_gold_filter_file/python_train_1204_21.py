n = int(input().strip())
a = [int(i) for i in input().strip().split()]
f = [0 for i in range(max(a)+1)]
l = len(f)

for i in a:
  f[i]+=1

if f[1]:
  f[1]=1

for i in range(2,l):
  for j in range(2*i,l,i):
    f[i]+=f[j]

print(max(f))
