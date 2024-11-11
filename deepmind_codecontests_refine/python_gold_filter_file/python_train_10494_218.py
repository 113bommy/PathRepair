n, a, b, c, d = [int(i) for i in input().split()]
S = ' ' + input()

if '##' in S[a:c + 1]:
    print('No')
elif '##' in S[b:d + 1]:
    print('No')
else:
    if c < d:
        print('Yes')
    elif '...' in S[b - 1:d + 2]:
        print('Yes')
    else:
        print('No')
