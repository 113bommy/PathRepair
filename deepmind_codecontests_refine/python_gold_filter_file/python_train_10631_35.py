n = int(input())
a = [*map(int, input().split())]

print(n+1)


b = [i + 10**5 for i in a]
print(1, n, 10**5)

print(2, 1, b[0])

for i in range(len(a) - 1):
    print(2, i+2, b[i+1] - (i+1))