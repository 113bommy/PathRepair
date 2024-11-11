def check_in(left, right, mid):
    return left <= mid <= right


def get_current_interval_n(min_weight, max_weight, x, n):
    res = False
    current_weight = x * n
    if min_weight <= current_weight <= max_weight:
        res = True

    div1 = min_weight - current_weight
    div2 = max_weight - current_weight

    return res, div1, div2


def search_x(left_l, rigth_r, n, xl, xr):
    x1 = xl
    x2 = xr
    mid = 0
    while x1 + 1 < x2:
        mid = (x1 + x2) // 2
        maybe, current_div1, current_div2 = get_current_interval_n(left_l, rigth_r, mid, n)
        if maybe:
            return True

        if current_div2 >= 0:
            x1 = mid
        elif current_div1 <= 0:
            x2 = mid
        else:
            return False
    # print("mid=", mid, "x1=", x1, "x2=", x2)
    current_weight1 = x1 * n
    current_weight2 = x2 * n
    if check_in(left_l, rigth_r, current_weight1) or check_in(left_l, rigth_r, current_weight2):
        return True
    elif n > 1:
        if n > rigth_r - current_weight1 > 0 and x1 < xr:
            return True
        elif n > abs(rigth_r - current_weight1) > 0 and x1 > xl:
            return True

    return False


n = int(input())

for i in range(n):
    k = input().split()
    k = [int(x) for x in k]
    l = k[3] - k[4]
    r = k[3] + k[4]
    xl = (k[1] - k[2])
    xr = (k[1] + k[2])

    if search_x(l, r, k[0], xl, xr):
        print("Yes")
    else:
        print("No")

