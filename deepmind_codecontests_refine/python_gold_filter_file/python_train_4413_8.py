def reversed_list(l, start, end):
    if start >= end:
        return l
    l[start], l[end] = l[end], l[start]
    return reversed_list(l, start + 1, end - 1)



def main_function():
    n = int(input())
    l = [int(i) for i in input().split(" ")]
    s_1, s_2 = sorted([int(i) - 1 for i in input().split(" ")])
    route_1 = 0
    route_2 = 0
    for i in range(len(l)):
        if i >= s_1 and i < s_2:
            route_1 += l[i]
        else:
            route_2 += l[i]
    return min(route_2, route_1)


print(main_function())