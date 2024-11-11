N = int(input())
print("Yes" if N % sum(map(int, str(N))) == 0 else "No")
