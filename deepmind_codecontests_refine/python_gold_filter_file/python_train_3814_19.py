a = ([31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31] * 4 + [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]) * 100

n = int(input())
b = list(map(int, input().split()))

m = len(a)

for i in range(len(a)):
    if b == a[i:i + n]:
        print("Yes")
        exit(0)
print("No")
