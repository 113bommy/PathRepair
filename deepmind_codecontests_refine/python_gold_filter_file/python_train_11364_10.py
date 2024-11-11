n = int(input())
a = [int(k) for k in input().split()]
b = [a[k]/max(k,n-k-1) for k in range(n)]
print(int(min(b)))