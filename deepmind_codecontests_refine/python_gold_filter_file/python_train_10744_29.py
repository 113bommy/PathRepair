def sol():
    a, b, c = sorted(map(int, input().split()))
    print("Yes" if a + b + 1 >= c else "No")


for i in range(int(input())):
    sol()
