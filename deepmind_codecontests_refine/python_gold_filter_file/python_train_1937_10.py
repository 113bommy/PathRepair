from math import factorial as f

infinity = 10 ** 9 + 1

def find_min(arr, exclude):
    min_elem = infinity
    count = 0
    for elem in arr:
        if elem not in exclude and elem < min_elem:
            min_elem = elem
            count = 1
        elif elem == min_elem:
            count += 1
    if min_elem == infinity:
        min_elem, count = 0, 0
    return (min_elem, count)
        
_ = int( input() )
arr = [int(i) for i in input().split()]

a_min, a_count = find_min(arr, [])
b_min, b_count = find_min(arr, [a_min])
c_min, c_count = find_min(arr, [a_min, b_min])

combinations = lambda n, m: f(n) // f(m) // f(n - m)

mins = [a_count, b_count, c_count]
sum_count = 0
res = 1

i = 0
while sum_count < 3 and i < len(mins):
    can_take = mins[i]
    can_take = min(can_take, 3 - sum_count)
    sum_count += can_take
    res *= combinations(mins[i], can_take)
    i += 1

print (res)
    


