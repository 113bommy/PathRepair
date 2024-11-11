import bisect

N=int(input())
D=[int(x) for x in input().split()]

D.sort()
total=0

for i in range(N-2):
    for j in range(i+1,N-1):
        total+=bisect.bisect_left(D,D[i]+D[j])-j-1

print(total)