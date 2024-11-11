N = int(input())

CSF = [[int(i) for i in input().split()] for _ in range(N-1)]
for i in range(N-1) :
    x = 0
    for j in range(i, N-1) :
        C, S, F = CSF[j]
        if x < S :
            x = S + C
        else :
            x = S + F * ((x - S + F - 1) // F) + C
    print(x)
print(0)