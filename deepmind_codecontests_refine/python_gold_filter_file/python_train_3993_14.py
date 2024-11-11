import math

n,m,a=map(int,input().split())
print("%s"%(math.ceil(n/a)*math.ceil(m/a)))