N = int(input())
A = [int(a) for a in input()]
def pascal_parity(n):
    def cnt2(m):
        a = m & -m
        return a.bit_length() - 1
    S = [0] * (n+1)
    for i in range(1, n):
        S[i] = S[i-1] + cnt2(n+1-i) - cnt2(i)
    return [1 if s == 0 else 0 for s in S]

def calc(L):
    return [abs(L[i] - L[i-1]) for i in range(1, len(L))]

def calc_all(L):
    for i in range(len(L)-1):
        L = calc(L)
    return L[0]

if N <= 5:
    print(calc_all(A))
else:
    A = calc(A)
    pp = pascal_parity(N-2)
    s = sum([a * pp[i] for i, a in enumerate(A)])
    if 1 in A:
        print(s % 2)
    else:
        print(s % 4)