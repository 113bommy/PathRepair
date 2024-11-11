import bisect

n, k, A, B = [int(x) for x in input().split()]
a_is = [int(x) - 1 for x in input().split()]

a_is.sort()

def how_many(i, j):
    count = bisect.bisect_left(a_is, j) - bisect.bisect_left(a_is, i)
    # print('i, j, count', i, j, count)
    return count


def get_cost(i, j):
    count = how_many(i, j)
    if count == 0:
        return A
    elif i + 1 == j:
        return B * count
    else:
        div = (j - i) // 2
        default = B * count * (j - i)
        left = get_cost(i, i + div)
        if left > default:
            return default

        right = get_cost(i + div, j)

        if left + right > default:
            return default
        else:
            return left + right


print(get_cost(0, 2**n))
