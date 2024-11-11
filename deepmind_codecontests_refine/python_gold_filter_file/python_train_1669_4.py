while True:
 H,W = map(int,input().split())
 if H==0 and W==0:
   break
 else:
   print('#'*W)
   for s in range(0,H-2):
     print('#'+'.'*(W-2)+'#')
   print("#"*W)     
   print()