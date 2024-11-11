import sys
readline = sys.stdin.readline
from collections import Counter

N = int(readline())
A = list(map(int, readline().split()))
B = 31

table = [0]*N

ans = 0
rev = 0
for b in range(B-1, -1, -1):
    one = Counter()
    zero = Counter()
    cnt = 0
    cntr = 0
    for i in range(N):
        a = (A[i]>>b)&1
        if a:
            one[table[i]] += 1
            cntr += zero[table[i]]
            table[i] += 1<<b
        else:
            zero[table[i]] += 1
            cnt += one[table[i]]
    
    if cntr < cnt:
        rev += cntr
        ans |= 1<<b
    else:
        rev += cnt

print(rev, ans)

        

