n = int(input())
a = list(map(int, input().split()))
rez = 0
otv = 0
for i in a:
    rez += i
    otv = min(otv, rez)
print(abs(otv))