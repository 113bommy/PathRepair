n = int(input())
k = int(input())
s = 0
mas = list(map(int, input().split()))
for i in range(len(mas) - 1):
    if mas[i] < n:
        s += n - mas[i]
print(s)