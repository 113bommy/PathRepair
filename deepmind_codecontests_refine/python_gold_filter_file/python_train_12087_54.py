import sys
 
read = lambda: sys.stdin.readline().rstrip()
 
n = int(read())
N = tuple(map(int,read().split()))
 
ans = 0
for i in range(n):
    ans += N[i]
 
print("HARD" if ans > 0 else "EASY")