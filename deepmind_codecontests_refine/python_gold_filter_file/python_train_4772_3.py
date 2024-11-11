s = "".join(sorted(input()))
t = "".join(sorted(input())[::-1])
print("Yes" if s < t else "No")