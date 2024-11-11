def read_nums():
    return list(map(int, input().strip().split()))

def read_int():
    return read_nums()[0]


N, K = read_nums()
boxes =read_nums()

best = -1, N, N
for i, val in enumerate(boxes):
    if N%val<=best[1]:
        best = i, N%val, N//val

print(best[0]+1, best[2])
