import math
n = int(input())
ls = list(map(int, input().split()))
pref = [0] * (n+1)
s = 0
for i in range(n):
    s += ls[i]
    pref[i+1] = s

for t in range(int(input())):
    a, b = list(map(int, input().split()))
    print( (pref[b]-pref[a-1]) // 10)
