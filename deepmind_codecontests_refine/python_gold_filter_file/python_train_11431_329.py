k, x = map(int, input().split())
print(*[i for i in range(x-(k-1), x+k)])