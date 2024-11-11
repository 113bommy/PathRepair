#Bhargey Mehta (Sophomore)
#DA-IICT, Gandhinagar
import sys, math, queue, bisect
#sys.stdin = open("input.txt", "r")
MOD = 10**9+7
sys.setrecursionlimit(1000000)

def ok(x):
    if a < x or b < x: return False
    if a//x + b//x  >= n:
        return True
    return False

n, a, b = map(int, input().split())
low, high = 1, a+b
while low <= high:
    mid = (low+high)//2
    if ok(mid):
        ans = mid
        low = mid+1
    else:
        high = mid-1
print(ans)
