def is_ok(a, b, k):
    for x in a:
        if abs(x - b) > k:
            return False

    return True

def is_greater(a, b, k):
    for x in a:
        if (abs(x - b) > k and x - b > k):
            return True

    return False


def is_smaller(a, b, k):
    for x in a:
        if (abs(x - b) > k and x - b < k):
            return True
    return False


q = int(input())

while q > 0 :
    q -= 1
    n, k = map(int, input().split())
    a =  list(map(int, input().split()))
    l = 1
    r = 1000000000
    ans = -1
    while (l <= r):
        mid = l  + (r - l) // 2
        # print(mid)
        if is_ok(a, mid, k):
            ans = mid
            l = mid + 1
        else:
            greater = is_greater(a, mid, k)
            smaller = is_smaller(a, mid, k)
            if greater and smaller:
                break
            elif greater:
                l = mid + 1
            else:
                r = mid - 1

    print(ans)
