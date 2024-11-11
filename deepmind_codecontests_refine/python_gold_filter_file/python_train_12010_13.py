N = int(input())
S = list(map(int, input().split()))
S.sort()
if S[0] == S[-1]:
    print("NO")
else:
    from bisect import *
    print(S[bisect_right(S, S[0])])    