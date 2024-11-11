K, Q = map(int, input().split())
*D, = map(int, input().split())
for q in range(Q):
    n, x, m = map(int, input().split())
    r = (n - 1) % K
    D1r_count0 = 0
    D1_count0 = 0
    D1_sum = 0
    D1r_sum = 0
    for k in range(K):
        if k < r:
            if D[k] % m == 0:
                D1r_count0 += 1
            D1r_sum += D[k] % m
        if D[k] % m == 0:
            D1_count0 += 1
        D1_sum += D[k] % m
    cnt_0 = D1_count0 * ((n - 1) // K) + D1r_count0
    a = x
    # 第n-1項を求める
    b = a + D1_sum * ((n - 1) // K) + D1r_sum
    # 繰り上がりの回数
    cnt_p = b // m - a // m
    cnt_n = (n - 1) - cnt_0 - cnt_p
    print(cnt_n)
