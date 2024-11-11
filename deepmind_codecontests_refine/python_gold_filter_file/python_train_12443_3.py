#!/usr/bin/env python3

from math import log

s, x = [int(x) for x in input().split()]

# sum == 0, xor == 0, one == 0 - both are 0 or 1 (2 variants)
# sum == 0, xor == 0, one == 1 - impossible
# sum == 0, xor == 1, one == 0 - impossible
# sum == 0, xor == 1, one == 1 - one 1 and another 1 is 0 (2 variants)
# sum == 1, xor == 0, one == 0 - impossible
# sum == 1, xor == 0, one == 1 - both are 0 or 1 (2 variants)
# sum == 1, xor == 1, one == 0 - one 1 and another 1 is 0 (2 variants)
# sum == 1, xor == 1, one == 1 - impossible

def get_count(size, one_bit, s, x):
    if size == 0 or \
            not one_bit and s == 0 and x == 0:
        return 1
    sum_bit = s & 1 != 0
    xor_bit = x & 1 != 0
    # print('size = {2:0>2}, sum_bit = {0}, xor_bit = {1}, one_bit = {3}'.format(sum_bit, xor_bit, size, one_bit))
    if not sum_bit and not xor_bit and one_bit or \
            not sum_bit and xor_bit and not one_bit or \
            sum_bit and not xor_bit and not one_bit or \
            sum_bit and xor_bit and one_bit:
                return 0
    s >>= 1
    x >>= 1
    size -= 1
    if not sum_bit and not xor_bit and not one_bit or \
            sum_bit and not xor_bit and one_bit:
                return get_count(size, False, s, x) + get_count(size, True, s, x)
    elif not sum_bit and xor_bit and one_bit:
        return 2 * get_count(size, True, s, x)
    else:
        return 2 * get_count(size, False, s, x)

size = int(log(1000000000000)/log(2)) + 5
count = get_count(size, False, s, x)
if s == x:
    assert count >= 2
    count -= 2 # numbers have to be > 0, so pairs with 0 aren't suitable
print(count)

