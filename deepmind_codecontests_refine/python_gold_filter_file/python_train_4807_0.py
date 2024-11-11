n = int(input())
mas = sorted(list(map(int, input().split())))
if mas[n-1]>=mas[n-2] + mas[n-3]:
    print("NO")
    exit()
print("YES")
for i in range(n-1, -1, -2):
    print(mas[i], end = " ")
for i in range(n%2, n, 2):
    print(mas[i], end = " ")
