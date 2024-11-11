a = list(map(int, input().split()))
print("win" if sum(a) <= 21 else "bust")