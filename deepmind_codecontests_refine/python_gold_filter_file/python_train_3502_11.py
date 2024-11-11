#!/usr/bin/python3.6
n, m = map(int, input().split())
d = {}

while n > 0:
    name, ip = input().split()
    d[ip + ";"] = name
    n -= 1

while m > 0:
    name, ip = input().split()
    print(name, ip, "#" + d[ip])
    m -= 1
