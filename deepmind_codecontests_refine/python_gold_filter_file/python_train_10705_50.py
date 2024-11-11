N = input()
if int(N) % sum(map(int, N)):
    print("No")
else:
    print("Yes")