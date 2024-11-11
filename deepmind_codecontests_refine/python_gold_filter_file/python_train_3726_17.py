def gaishin(p,q,r):
  a = ((q[0]-r[0])**2+(q[1]-r[1])**2)**(0.5) #qとrの間
  b = ((r[0]-p[0])**2+(r[1]-p[1])**2)**(0.5) #rとpの間
  c = ((p[0]-q[0])**2+(p[1]-q[1])**2)**(0.5) #pとqの間
  cosp = (b**2+c**2-a**2)/(2*b*c)
  cosq = (c**2+a**2-b**2)/(2*c*a)
  cosr = (a**2+b**2-c**2)/(2*a*b)
  if cosp >= 1: cosp = 1
  if cosp <= -1: cosp = -1
  if cosq >= 1: cosq = 1
  if cosq <= -1: cosq = -1
  if cosr >= 1: cosr = 1
  if cosr <= -1: cosr = -1
  sinp = (1-cosp**2)**(0.5)
  sinq = (1-cosq**2)**(0.5)
  sinr = (1-cosr**2)**(0.5)
  sin2p = 2*sinp*cosp
  sin2q = 2*sinq*cosq
  sin2r = 2*sinr*cosr
  if sin2p+sin2q+sin2r == 0:
    infinite = float("inf")
    return (infinite, infinite)
  x = (sin2p*p[0]+sin2q*q[0]+sin2r*r[0])/(sin2p+sin2q+sin2r)
  y = (sin2p*p[1]+sin2q*q[1]+sin2r*r[1])/(sin2p+sin2q+sin2r)
  #R = a/(2*sinp) #正弦定理による外接円
  return (x,y)

N = int(input())
A = []
for i in range(N):
  x,y = map(int,input().split())
  A.append((x,y))
INF = float("inf")
ans = INF
for i in range(N):
  for j in range(i+1,N):
    z = ((A[i][0]+A[j][0])/2,(A[i][1]+A[j][1])/2) #二点の中心
    dx = A[i][0]-A[j][0]
    dy = A[i][1]-A[j][1]
    hankei = ((dx**2+dy**2)**(0.5))/2
    Flag = True
    for t in range(N):
      if t == i or t == j: #選んだ二点ならスキップ
        continue
      temp = ((z[0]-A[t][0])**2+(z[1]-A[t][1])**2)**(0.5)
      hankei = max(hankei,temp)
    ans = min(ans,hankei)
#print(ans)
if N == 2:
  print(ans)
  exit()
for i in range(N):
  for j in range(i+1,N):
    for k in range(j+1,N):
      p = A[i]; q = A[j]; r = A[k]
      z = gaishin(p,q,r)
      #print(z)
      hankei = 0
      for t in range(N):
        temp = ((z[0]-A[t][0])**2+(z[1]-A[t][1])**2)**(0.5)
        hankei = max(hankei,temp)
      ans = min(ans,hankei)
print(ans)