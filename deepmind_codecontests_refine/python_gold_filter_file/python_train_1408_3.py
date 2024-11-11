n, m = map(int, input().split())
low = 1
high = 10**9


def p(x):
    t1 = x//2
    t2 = x//3
    if t1 >= n and t2 >= m:
        t3 = x//6
        return t1+t2-t3 >= m+n
    return False


while low < high:
    mid = low + (high-low)//2
    if p(mid):
        high = mid
    else:
        low = mid+1

print(low)
