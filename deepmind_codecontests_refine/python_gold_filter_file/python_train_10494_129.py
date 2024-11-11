N, A, B, C, D = map(int, input().split())
S = input()

A -= 1
B -= 1
C -= 1
D -= 1

if '##' in S[A:C] or '##' in S[B:D]:
    print("No")
    exit()
if C > D:
    if  '...' not in S[B-1:D+2]:
        print("No")
        exit()
print("Yes")


