import sys

q = int(sys.stdin.readline())

for _ in range(q):
    n = int(sys.stdin.readline())
    stack = []
    temp = n
    while temp != 0:
        stack.append(temp % 3)
        temp = temp // 3
    stack.reverse()
    stack = list(map(int, stack))
    # print(stack)
    if stack[0] == 2:
        stack = [1] + [0] * len(stack)
    else:
        judge = False
        is_two = False
        for i in range(1, len(stack)):
            if stack[i] == 2:
                is_two = True
                for j in range(i, -1, -1):
                    if stack[j] == 0:
                        stack[j] = 1
                        stack = stack[:j+1] + [0] * (len(stack)-j-1)
                        judge = True
                        break
                break
        if judge == False and is_two == True:
            stack = [1] + [0]*(len(stack))
    power = len(stack)-1
    m = 0
    # print(stack)
    for j in range(len(stack)):
        m += stack[j]*(3**power)
        power -= 1
    print(m)
