import sys

a, b = map(int, sys.stdin.readline().split())
temp = False

while True:
    if a > b:
        break
    for i in str(a):
        if str(a).count(i) != 1:
            a += 1
            break
    else:
        temp = True
    if temp:
        break

if temp:
    print(a)
else:
    print(-1)