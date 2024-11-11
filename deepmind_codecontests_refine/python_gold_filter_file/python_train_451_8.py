def inp():
    return map(int, input().split())


t, l_count, r_count = int(input()), 0, 0
for i in range(t):
    l, r = inp()
    l_count += l
    r_count += r

l_count, r_count = min(t- l_count, l_count), min(t- r_count, r_count)
print(l_count + r_count)
