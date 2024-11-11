a = int(input())
lst = [int(x) for x in input().split()]
help_lst = [None] * a
help_lst[0] = (str(lst[1] - lst[0]), str(lst[-1] - lst[0]))
help_lst[-1] = (str(len(range(lst[-2], lst[-1]))), str(len(range(lst[0], lst[-1]))))
for i in range(1, a - 1):
    city_max = max(lst[i] - lst[0], lst[-1] - lst[i])
    city_min = min(lst[i] - lst[i - 1], lst[i + 1] - lst[i])
    help_lst[i] = (str(city_min), str(city_max))
for pair in help_lst:
    print(' '.join(pair))
