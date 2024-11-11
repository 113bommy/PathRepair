import math
import statistics
t=int(input())
for i in range(t):
    n=int(input())
    x=list(map(int,input().split()))
    #for i in range(len(x)):
    a=math.ceil(statistics.mean(x))
    print(a)        