S = "".join(sorted(input()))
T = "".join(sorted(input()))[::-1]

print("Yes" if (S < T) else "No")

