import sys
s=0
p=[list(map(float,e.split(',')))for e in sys.stdin]
x,y=p[0]
print(abs(sum((p[i][0]-x)*(p[i+1][1]-y)-(p[i][1]-y)*(p[i+1][0]-x)for i in range(1,len(p)-1)))/2)
