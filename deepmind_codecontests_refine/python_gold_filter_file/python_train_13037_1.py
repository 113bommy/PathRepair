
def find_leftmost_right(a, k):
    return indices[a][-k]


def most_repeats(j1, j2):
    if j2 >= j1:
        return max(repeats[j0][j2]-repeats[j0][j1-1] for j0 in range(200))
    return 0


T = int(input())

for t in range(T):
    N = int(input())
    A = list(map(int, input().split()))

    repeats = [[0]*N for _ in range(200)]
    indices = [[] for _ in range(200)]
    for i in range(0, N):
        if i > 0:
            for j in range(200):
                repeats[j][i] = repeats[j][i-1]
        repeats[A[i]-1][i] += 1
        indices[A[i]].append(i)

    result = 1
    for i1 in range(len(A)):
        c = repeats[A[i1]-1][i1]
        i2 = find_leftmost_right(A[i1], c)

        if i2 > i1:
            # print("{}\n c is {} i1 is {} i2 is {} most_repeats is {}".
            #       format(A, c, i1, i2, most_repeats(i1 + 1, i2 - 1)))
            result = max(result, 2 * c + most_repeats(i1+1, i2-1))
    print(result)