H, W = map(int, input().split())
while True:
 if H == 0 and W == 0:
  break
 for h in range(H):
  if h%2 == 0:
   print("#."*(W//2) + "#"*(W%2))
  else:
   print(".#"*(W//2) + "."*(W%2))
 print()

 H, W = map(int, input().split())