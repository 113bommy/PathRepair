#Contest 1382    Round 658 div2
import sys
I = lambda : int(input())
readline = lambda: sys.stdin.readline().strip('\n')
readgen  = lambda: map(int,readline().split())


#A: Common subsequence
R = readgen
S = lambda: set(R())
for _ in range(I()):
    a,b = R()
    inter = S().intersection(S())
    if inter:
        print('YES\n1 %d'%inter.pop())
    else:
        print('NO')
