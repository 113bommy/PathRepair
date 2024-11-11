def valid(k, mid):
    return (2*k - mid - 1) * mid // 2 + 1
    
def binary_search(n, k):
    l, r = 0, k-1
    while (l <= r):
        mid = l+r >> 1
        if (valid(k, mid) < n):
            l = mid+1
        else:
            r = mid-1
    return l

def main():
    n, k = map(int, input().split())
    res = binary_search(n, k)
    print(-1 if res == k else res)

main()
