from sys import stdin
x, y = map(int, stdin.readline().split())
for i in range(1,11):
    if x * i % 10 == y or x * i % 10 == 0:
        print(i)
        break