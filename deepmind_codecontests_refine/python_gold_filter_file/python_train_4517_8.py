def main():
    n, k =  map(int, input().strip().split())
    return list(range(n, n - k, -1)) + list(range(1, n - k + 1))


print(*main())