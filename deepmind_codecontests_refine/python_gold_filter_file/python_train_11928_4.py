n=int(input())
mx=10**9
mn=-10**9
r=0
for i in range(n):
   c,d=[int(j) for j in input().split()]
   if d==1:
      mn=max(mn,1900-r)
   else:
      mx=min(mx,1899-r)
   r+=c
if mx==10**9:
   print("Infinity")
elif mn>mx:
   print("Impossible")
else:
   print(mx+r)