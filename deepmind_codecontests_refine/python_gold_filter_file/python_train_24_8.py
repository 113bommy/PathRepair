import sys

T = int(sys.stdin.readline())
for _ in range(T):
    N = int(sys.stdin.readline())
    list_num = list(map(int, sys.stdin.readline().split()))
    if list_num[-1] >= list_num[0] + list_num[1]:
        print(1, 2, N)
    else:
        print(-1)