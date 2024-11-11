n, k = map(int, input().split())
al = list(map(int, input().split()))
for i in range(k, n):
    print('Yes' if al[i] > al[i - k] else 'No')