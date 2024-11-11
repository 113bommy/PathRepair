#coding=utf-8


a, b = list(map(int, input().strip().split()))
count = a
while a // b >= 1:
    count += a // b
    a = a // b + a % b
print(count)


