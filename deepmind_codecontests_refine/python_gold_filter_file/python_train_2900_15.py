i,o,t,j,l,s,z = map(int, input().split())
k = o
p = (i//2 + j//2 + l//2)*2
q = 0
if i*j*l:
  q = ((i-1)//2 + (j-1)//2 + (l-1)//2)*2 + 3
print(k + max(p, q)) 
