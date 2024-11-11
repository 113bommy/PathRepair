import sys
input = lambda: sys.stdin.readline().rstrip()

for _ in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    if len(set(a))==1:
        print(n)
    else:
        print(1)