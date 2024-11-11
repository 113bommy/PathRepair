k=int(input())
o=[-1,1]
while k>-1:
 o+=[min(k+2,10**6)]
 k-=o[-1]-1
print(len(o))
print(*o)
