# -*- coding: utf-8 -*-

N, A, B, C, D = map(int, input().split())
S = input()

if '##' in S[A:max(C, D)]:
    print('No')
elif C<D:
    print('Yes')
else:
    if '...' in S[B-2:D+1]:
        print('Yes')
    else:
        print('No')