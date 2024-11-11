n = int(input())
datasets = [0]*n
#datasets[k] == [x1k,y1k,x2k,y2k,x3k,y3k]
for i in range(0,n):
  datasets[i] = list(map(float,input().split()))

for data in datasets:
  x1p2=(data[0]+data[2])
  x1m2=(data[0]-data[2])
  x1p3=(data[0]+data[4])
  x1m3=(data[0]-data[4])
  y1p2=(data[1]+data[3])
  y1m2=(data[1]-data[3])
  y1p3=(data[1]+data[5])
  y1m3=(data[1]-data[5])
  x=(x1p2*x1m2*y1m3+y1p2*y1m2*y1m3-x1p3*x1m3*y1m2-y1p3*y1m3*y1m2)/(2*(x1m2*y1m3-x1m3*y1m2))
  y=(y1p2*y1m2*x1m3+x1p2*x1m2*x1m3-y1p3*y1m3*x1m2-x1p3*x1m3*x1m2)/(2*(y1m2*x1m3-y1m3*x1m2))
  r=((x-data[0])**2+(y-data[1])**2)**(1/2)
  if x == 0.000:
    x=0
  if y == 0.000:
    y=0
  print("{0:.3f} {1:.3f} {2:.3f}".format(x,y,r))