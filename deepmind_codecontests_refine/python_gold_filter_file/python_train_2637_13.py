from math import ceil

n = int(input())
s = [int(i) for i in input().split(' ')]

group = [s.count(i) for i in range(1,5)]

taxi = group[3] + group [2] + group[1]//2

if group[0] > group[2]:
    taxi += ceil((group[0]-group[2] + group[1]%2*2)/4)
else:
    taxi+= group[1]%2

print(taxi)