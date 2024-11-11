import bisect
a,b,c=map(int,input().split(' '))
times=[]
for i in range(10**6):
    times.append(b*(i+1))
pos=bisect.bisect_left(times,(a-b)*c,0,len(times))
print(pos+1)

