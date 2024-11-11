import sys
from math import factorial
f = sys.stdin
#f = open("input.txt", "r")
f. readline()
t = [int(i) for i in f.readline().strip().split()]
times = dict().fromkeys(t)
for i in times:
    times[i] = t.count(i)
count = 0
for i in times.keys():
    if i!=0 and -1*i in times.keys():
        count += times[i]*times[-1*i]
        times[i] = 0
        times[-1*i] = 0
try:
    count += sum(range(times[0]))
except:
    pass
print(count)