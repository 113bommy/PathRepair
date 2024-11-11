s, limit = [int(c) for c in input().split()]


def lowbit(a):
    res = 1
    while a % 2 == 0:
        res += 1
        a = a // 2

    return res

a = [0] * 20
examples = [[] for _ in range(20)]



for i in range(1, limit+1):
    a[lowbit(i)] += 1
    examples[lowbit(i)].append(i)

length = -1
res = []
c = 1
#
# print(a)
# print(examples)

while s != 0:
    if s <= a[1]:
        res = res + examples[1][:s]
        length += s
        s = 0
    else:
        # print("{0:b}".format(s))
        max_pow = len("{0:b}".format(s))
        while max_pow != 1 and a[max_pow] == 0:
            max_pow -= 1

        if max_pow == 1:
            length = -2
            s = 0
        else:
            # print(s, 2**(max_pow-1))
            s = s - 2**(max_pow-1)
            length +=1
            ex = examples[max_pow].pop()
            a[max_pow] -= 1
            res.append(ex)


print(length + 1)

if length >= 0:
    print(' '.join(map(str,res)))