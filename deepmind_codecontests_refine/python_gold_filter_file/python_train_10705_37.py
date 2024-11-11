N = input()

X = sum(map(int, N))
print ("Yes" if int(N) % X == 0 else "No")