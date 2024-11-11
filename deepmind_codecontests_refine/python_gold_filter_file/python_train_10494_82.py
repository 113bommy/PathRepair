N, A, B, C, D = map(int, input().split())
S = input()

if C < D:
    if '##' in S[A-1:C] or '##' in S[B-1:D]:
        print('No')
    else:
        print('Yes')
else:
    if '...' in S[B-2:D+1] and '##' not in S[A-1:C]:
        print('Yes')
    else:
        print('No')

