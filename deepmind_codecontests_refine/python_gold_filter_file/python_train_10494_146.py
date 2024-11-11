N,A,B,C,D = map(int,input().split())
S = input()

flg = 0
cnt = 0
S_ac = S[A:C]
S_bd = S[B:D]

if '##' in S_ac or '##' in S_bd:
    flg = 1

if D < C and flg == 0:
    S = S[B-2:D+1]
    if '...' not in S:
        flg = 1

if flg == 1:
    print('No')
else:
    print('Yes')