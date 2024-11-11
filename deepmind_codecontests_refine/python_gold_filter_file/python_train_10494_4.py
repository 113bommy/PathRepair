N, A, B, C, D = map(int, input().split())
S = input()

if S[A-1:max([C, D])].find('##') != -1:
    print('No')
    exit()

if C < D:
    print('Yes')
    exit()

if S[B-2:D+1].find('...') >= 0:
    print('Yes')
else:
    print('No')