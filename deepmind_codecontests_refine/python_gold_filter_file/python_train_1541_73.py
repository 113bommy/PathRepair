As = list(map(int, input().split()))

print("bust" if sum(As) >= 22 else "win")