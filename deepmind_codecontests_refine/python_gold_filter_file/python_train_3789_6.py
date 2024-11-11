import sys

n,m = sys.stdin.readline().split()
n = int(n)
m = int(m)

while True:
    num_arr = [int(i) for i in sys.stdin.readline().split(' ')]
    operation_arr = []
    last_sum = 0
    change_map = {}
    for i in range(0,m):
        operation = sys.stdin.readline().split(' ')
        id = int(operation[0])
        if id == 1:
            idx, value = int(operation[1]), int(operation[2])
        else:
            value = int(operation[1])

        if id == 1:
            operation_arr.append(last_sum)
            change_map[idx - 1] = i
            num_arr[idx - 1] = value
        elif id == 2:
            operation_arr.append(value + last_sum)
            last_sum += value
        elif id == 3:
            value -= 1
            operation_arr.append(last_sum)
            if value in change_map:
                print(num_arr[value] + last_sum - operation_arr[change_map[value]])
            else:
                print(num_arr[value] + last_sum)


    nm = sys.stdin.readline().split()
    if not nm:
        break
    else:
        n,m = nm
        n = int(n)
        m = int(m)
