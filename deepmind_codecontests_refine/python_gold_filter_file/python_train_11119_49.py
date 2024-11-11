
lst = list(int(input()) for _ in range(6))

print("Yay!" if lst[4] - lst[0] <= lst[5] else ":(")