N = int(input())
for X in range(N+1):
    if int(X*1.08) == N:
        print(X)
        exit()

print(":(")