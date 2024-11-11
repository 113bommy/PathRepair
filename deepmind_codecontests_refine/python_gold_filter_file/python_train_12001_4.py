from sys import stdin, stdout
from collections import deque
import bisect
R = lambda : stdin.readline().strip()
RL = lambda f=None: list(map(f, R().split(' '))) if f else list(R().split(' '))
output = lambda x: stdout.write(str(x) + '\n')
output_list = lambda x: output(' '.join(map(str, x)))

T = int(input())
for _ in range(T):
    n,k = RL(int)
    l = RL(int)
    mi = min(l)
    ans = 0
    for i in range(n):
        ans+=(k-l[i])//mi
    ans-=(k-mi)//mi
    print(ans)