N, S = list(map(int, input().split()))
if S >= 2 * N:
    print("YES")
    res = [2] * (N - 1) + [(S - 2 * (N - 1))]
    print(" ".join(map(str, res)))
    print(1)
else:
    print("NO")
