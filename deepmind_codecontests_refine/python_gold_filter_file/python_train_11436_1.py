N = int(input())
S = input()

T = [+1 if s=='(' else -1 for s in S]

from itertools import accumulate
Tcumsum = list(accumulate(T))

i = max(0, - min(Tcumsum))

print('(' * i + S + ')' * (Tcumsum[-1]+i))