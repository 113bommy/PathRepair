I = lambda: map(int, input().split())

n, A, B = I()
s1, *S = I()

if S:
    S = sorted(S)
    total = s1
    i = 0
    while i < n-1 and s1*A >= B*(total+S[i]):
        total += S[i]
        i += 1
    print(n-i-1)
else:
    print(0)