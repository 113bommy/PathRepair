import sys
f = sys.stdin
n = int(f.readline())
arr = list(map(int, f.readline().strip().split()))
odd = 0
for i in range(n):
    for j in range(i):
        odd ^= (arr[i]<arr[j])
m = int(f.readline())
while m:
    l, r = map(int, f.readline().strip().split())
    x = r-l+1
    odd ^= (((x*(x-1)) >> 1)%2)
    if odd:
        print("odd")
    else:
        print("even")
    m -= 1