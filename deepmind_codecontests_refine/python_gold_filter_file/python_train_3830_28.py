def abc155_d():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()

    from bisect import bisect_left, bisect_right
    lower = -10**18
    upper = 10**18
    while upper - lower > 1:
        x = (upper + lower) // 2
        cnt = 0
        for i in range(n-1):
            a = A[i]
            if a < 0:
                idx = bisect_left(A, (x+a+1)//a)
                cnt += n - max(idx, i+1)
            elif a > 0:
                idx = bisect_right(A, x//a)
                cnt += max(0, idx - i - 1)
            else:  # a == 0
                if x >= 0:
                    cnt += n - i - 1
            if cnt >= k: break
        if cnt >= k: upper = x
        else: lower = x
    print(upper)

if __name__ == '__main__':
    abc155_d()