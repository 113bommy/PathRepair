a = input()
b = input()

print("Yes" if sorted(a) < sorted(b)[::-1] else "No")
