[h_1,h_2] = [int(x) for x in input().split(' ')]
[a,b] = [int(y) for y in input().split(' ')]

k = 0
p_0 = h_1 + (10-2)*a

if h_2 > p_0:
    if a <= b:
        k = -1
    else:
        while h_2 > p_0:
            p_0 += 12*(a-b)
            k += 1

print(k)