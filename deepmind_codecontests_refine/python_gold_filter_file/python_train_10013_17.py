b=int(input())
g=int(input())
n=int(input())
if b>=n and g>=n:
 print(n+1)

elif b>=n and g<n:
 print(n+1-(n-g))

elif g>=n and b<n:
 print(n+1-(n-b))

elif g<n and b<n:
 print(n+1-(n-b)-(n-g))

