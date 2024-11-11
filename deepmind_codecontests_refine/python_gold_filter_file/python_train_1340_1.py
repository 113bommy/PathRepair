import sys
a=[0]*4001
for i in range(2000):a[i]=a[4000-i]=(i+3)*(i+2)*(i+1)//6-a[i-1001]*4*(i>999)
for e in sys.stdin:print(a[int(e)])
