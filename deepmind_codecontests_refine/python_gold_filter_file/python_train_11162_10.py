import sys
input = sys.stdin.readline
n = int(input())
xy = [list(map(int,input().split())) for i in range(n)]
if n%2:
  print("NO")
else:
  xyt = list(zip(*xy))
  cx,cy = max(xyt[0])+min(xyt[0]),max(xyt[1])+min(xyt[1])
  for i in range(n):
    x,y = xy[i]
    xt,yt = xy[(i+n//2)%n]
    if cx != xt+x or cy != yt+y:
      print("NO")
      break
  else:
    print("YES")