def suma(n):
    return n*(n+1)//2

def sumaij(i, j):
    if i <= 1:
        return suma(j)
    return suma(j) - suma(i-1)

def bin_search_solution(n, k):
    st, end = 1, k
    while st < end:
        mid = (st+end)//2
        s = sumaij(mid, k)
        if s == n:
            return k - mid + 1
        if s > n:
            st = mid + 1
        else:
            end = mid
    return k - st + 2
            

def solve():
    n, k = map(int, input().split())
    if n == 1:
        print(0)
    elif k >= n:
        print(1)
    else:
        n -= 1
        k -= 1
    
        if suma(k) < n:
            print(-1)
        else:
            res = bin_search_solution(n, k)
            print(res)

if __name__ == '__main__':
    solve()
