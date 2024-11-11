import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)


############ ---- Input Functions ---- ############
def in_int():
    return (int(input()))


def in_list():
    return (list(map(int, input().split())))


def in_str():
    s = input()
    return (list(s[:len(s) - 1]))


def in_ints():
    return (map(int, input().split()))

mod = 7 + 10**9



n,m = in_ints()

xx = 0
yy = 0
print(min(m,n)+1)
for i in range(min(m,n)+1):
    print(i, min(m,n)-i)
