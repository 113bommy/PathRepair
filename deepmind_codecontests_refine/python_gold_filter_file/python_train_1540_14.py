n = int(input().split()[0])
print(max(-1, n - sum(map(int, input().split()))))