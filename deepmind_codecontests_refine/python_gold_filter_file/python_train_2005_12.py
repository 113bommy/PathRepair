


list_input = lambda: list(map(int, input().split()))
int_input = lambda: int(input())

def count_vals(l):
    d = {}
    for i in l:
        d[i] = d.get(i, 0) + 1
    return d


def bit_inv(b):
    if b == '1':
        return '0'
    else:
        return '1'

def opp(s, n):
    for i in range((n + 1) // 2):
        # print(s[i], s[n-i])
        s[i], s[n-i] = bit_inv(s[n-i]), bit_inv(s[i])
        
    if (n + 1) % 2:
        s[(n + 1) // 2] = bit_inv(s[(n + 1) // 2])

    # print(n, ''.join(s))
    return s


def solve(a, b, n):
    l = []
    for i in range(n-1, 0, -1):
        x = a[0]
        if x == b[i]:
            a[0] = bit_inv(a[0])
            l.append(1)
            l.append(i+1)
        else:
            l.append(i+1)

        # a[0] = bit_inv(a[i])
        # print(i, a[0])
        a = opp(a, i)
        # print(a)


    if a[0] != b[0]:
        l.append(1)
        a[0] = bit_inv(a[0])

    return l

#
#
# for _ in range(int_input()):
#     n = int_input()
#     a = list(input())
#     b = list(input())
#
#     l = []
#     for i in range(n-1, 0, -1):
#         x = a[0]
#         if x == b[i]:
#             l.append(1)
#             l.append(i+1)
#         else:
#             l.append(i+1)
#         a[0] = bit_inv(a[i])
#         print(i, a[0])
#
#
#     if a[0] != b[0]:
#         l.append(1)
#         a[0] = bit_inv(a[0])
#
#     print(len(l), end=" ")
#     print(*l)


for _ in range(int(input())):
    n = int_input()
    a = list(input())
    b = list(input())

    l = solve(a, b, n)

    print(len(l), end=" ")
    print(*l)