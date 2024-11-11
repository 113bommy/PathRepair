S, T = input().split()
a, b = map(int, input().split())
U = input().strip()
print(a - (S == U), b - (T == U))