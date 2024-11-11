N, A, B, C, D = map(int, input().split())
S = input()
if C < D:
    if '##' not in S[A:D - 1]:
        print('Yes')
    else:
        print('No')
else:
    if '...' in S[B - 2:D + 1] and '##' not in S[A:C - 1]:
        print('Yes')
    else:
        print('No')