def d_3n_numbers(N, A):
    import heapq
    left = A[:N]
    heapq.heapify(left)
    # heappopはキューの最小値を取り出すが、rightからは最大値を取り出したいので-1を掛ける
    # 後にマイナスが付いているところは、それの帳尻を合わせている
    right = [-i for i in A[2 * N:]]
    heapq.heapify(right)

    # 最初、leftには数列の先頭N個が、rightには末尾N個が格納されている
    # 数列のN番目から2N番目まで順に、leftに格納して最小値を捨てることを繰り返す
    # 数列の2N番目からN番目まで順に、rightに格納して最大値を捨てることを繰り返す
    left_sum = [sum(left)]
    right_sum = [-sum(right)]
    for k in range(N, 2 * N):
        heapq.heappush(left, A[k])
        v = heapq.heappop(left)
        left_sum.append(left_sum[-1] + A[k] - v)
    for k in range(2 * N - 1, N - 1, -1):
        heapq.heappush(right, -A[k])
        v = heapq.heappop(right)
        right_sum.append(right_sum[-1] + A[k] - (-v))

    score = [a - b for a, b in zip(left_sum, right_sum[::-1])]
    return max(score)

N = int(input())
A = [int(i) for i in input().split()]
print(d_3n_numbers(N, A))