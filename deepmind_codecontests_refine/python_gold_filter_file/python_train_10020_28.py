import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    node = 0
    for _ in range(n-1):
        a, b = map(int, input().split())
        if a==x or b==x:
            node += 1
    if node<=1 or n%2==0:
        print('Ayush')
    else:
        print('Ashish')