a, b = tuple(map(int, input().split()))
print((b*(b-1)*a*(a+1)*b//4 + a*b*(b-1) // 2) % 1000000007)