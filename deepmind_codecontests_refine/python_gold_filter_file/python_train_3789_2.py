n,m = [int(x) for x in input().split(' ')]
array = [int(x) for x in input().split(' ')]

add = 0

for i in range(m):
    op = [int(w) for w in input().split(' ')]
    op_type = op[0]

    if op_type == 3:
        print(array[op[1] - 1] + add)
    elif op_type == 2:
        add += op[1]
    else:
        v = op[1]
        x = op[2]
        array[v-1] = x - add