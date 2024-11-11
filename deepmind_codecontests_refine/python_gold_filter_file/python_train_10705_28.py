N = input()
f = sum(map(int, N))
print("Yes" if int(N) % f == 0 else "No")
