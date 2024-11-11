from collections import defaultdict
import math
n=int(input())
points=[]
lines1=defaultdict(set)
lines=[]
parallel=defaultdict(list)
lines_=0
parallel_=0
for i in range(n):
    x,y=input().split()
    x,y=[int(x),int(y)]
    points.append([x,y])
#print(points)
points.sort()
count=0
for i in range(n):
    for j in range(i):
        #print(points[i][1],points[j][1])
        a=points[i][1]-points[j][1]
        b=points[i][0]-points[j][0]
        c=points[i][1]*points[j][0]-points[j][1]*points[i][0]
        gcd_=math.gcd(a,(math.gcd(b,c)))
        a,b,c=a//gcd_,b//gcd_,c//gcd_
        #print(a,b,c,points[i],points[j])
        #print(c,count)
        count+=1
        lines1[(a,b)].add(c)
        if [a,b,c] not in lines:
            lines.append([a,b,c])
            lines_+=1
#print(lines)
#print(len(lines))
s=0
for v in lines1.values():
  s += len(v)
lines2 = s * (s-1) // 2
for i,value in lines1.items():
    s=len(value)
    lines2-=(s * (s-1)) // 2
print(lines2)

    
