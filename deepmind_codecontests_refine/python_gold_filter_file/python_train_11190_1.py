__author__ = 'taras-sereda'
from itertools import takewhile
from functools import partial
def vanjva_v():

    w, m = map(int, input().split())
    #
    # powers = filter(lambda x: x<)
    # ordered_powers = sorted(powers, key=lambda x: m-x)
    base_w = partial(pow, w)
    powers = list(takewhile(lambda x: x<= m, map(base_w, range(101))))
    powers.append(base_w(len(powers)))
    # powers = list(map(lambda x: w**x, range(101)))
    # print(powers)
    if w == 2 or w == 3:
        return "YES"
    while m != 0 and powers:

        min_dif = min(map(lambda x: abs(m-x), powers))
        # print(min_dif)
        remains = sorted(filter(lambda x: abs(x-m) == min_dif, powers), reverse=True)
        taken = remains[0]
        if m < taken:
            m = taken - m
        else:
            m -= taken
        powers.remove(taken)
        # print(m, taken, powers)
    return "YES" if not m else "NO"
    s_powers = sorted(powers, key=lambda x: -(x-m))
    # return (powers,s_powers)

if __name__ == "__main__":
    print(vanjva_v())
