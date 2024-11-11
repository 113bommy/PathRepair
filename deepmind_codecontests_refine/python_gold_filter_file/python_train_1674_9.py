H, W =map(int, input().split())
while not (H == 0 and W == 0):
 for h in range(H):
  if h == 0 or h == H-1:
   print("#" * W)
  else:
   print("#" + "."*(W-2) + "#")
 print()
 H, W =map(int, input().split())