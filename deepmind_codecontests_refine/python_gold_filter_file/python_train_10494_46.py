N,A,B,C,D = map(int,input().split())
s = input()
if ('##' in s[A:C]) or ('##' in s[B:D]):
    print('No')
else:
    if C > D:
        if '...' in s[B-2:D+1]:
            print('Yes')
        else:
            print('No')
    else:
        print('Yes')