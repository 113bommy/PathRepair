i,o,t,j,l,s,z = map(int,input().split())
if i > 0 and j > 0 and l > 0:
  print(max(o + i//2*2 + j//2*2 + l//2*2,o + (i-1)//2*2 + (j-1)//2*2 + (l-1)//2*2 + 3))
else:
  print(o + i//2*2 + j//2*2 + l//2*2)
