import sys
import bisect
input = sys.stdin.readline
ins = lambda: input().rstrip()
ini = lambda: int(input().rstrip())
inm = lambda: map(int, input().rstrip().split())
inl = lambda: list(map(int, input().split()))
out = lambda x, s='\n': print(s.join(map(str, x)))

n, x, y = inm()
a = sorted(inl())
if x > y:
    print(n)
else:
    ans = bisect.bisect_right(a, x)
    print((ans + 1) // 2)