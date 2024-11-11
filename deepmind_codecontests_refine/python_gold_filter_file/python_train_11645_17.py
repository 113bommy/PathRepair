N, A, B = [int(i) for i in input().split()]
res = max(0, (N-2) * B - (N-2) * A + 1)
print(res)