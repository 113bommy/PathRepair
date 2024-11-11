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


def in_ints() -> object:
    return (map(int, input().split()))

t = in_int()

for tt in range(t):
    n = in_int()
    a = in_list()
    b = in_list()
    a1 = [[False,False, False] for i in range(n)]

    a1[0][a[0]] = True

    for i in range(1, len(a)):
        a1[i] = list(a1[i-1])
        a1[i][a[i]] = True

    ans  = True

    if a[0] != b[0]:
        print('NO')
    else:
        for i in range(len(a)-2,-1,-1):
            if b[i+1] > a[i+1] and a1[i][1] == False:
                ans =  False
            if b[i+1] < a[i+1] and a1[i][-1] == False:
                ans = False

        if ans:
            print('YES')
        else:
            print('NO')

