n = int(input())
a = list(map(int, input().split()))
ans = (sum(a) // (n - 1)) + int(sum(a) % (n - 1) != 0)
print(max(max(a), ans))