x = input()
fx = sum(map(int, x))
print("Yes" if int(x) % fx == 0 else "No")