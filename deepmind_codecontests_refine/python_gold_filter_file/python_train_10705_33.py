n = input()
if int(n) % sum(map(int, n)):
    print("No")
else:
    print("Yes")