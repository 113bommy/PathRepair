
import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = set()
    for i in range(1, n+1):
        if i**2>n:
            break
        elif i**3 <= n:
            a.add(i**3)
        a.add(i**2)
    print(len(a))

