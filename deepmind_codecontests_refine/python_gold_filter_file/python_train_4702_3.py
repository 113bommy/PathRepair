index = 1
x = 0
overflow = 2**32-1
innerLoop = []
numberOfTimes = int(input())

while index <= numberOfTimes:
    entry = input().split()
    if entry[0] == "for":
        if len(innerLoop) == 0:
            innerLoop.append(int(entry[1]))
        else:
            if innerLoop[-1] != -1 and innerLoop[-1] * int(entry[1]) < overflow:
                innerLoop.append(innerLoop[-1] * int(entry[1]))
            else:
                innerLoop.append(-1)
    elif entry[0] == "end":
        innerLoop.pop()
    else:
        if len(innerLoop) != 0 and innerLoop[-1] == -1:
            x = 2**33
            break
        elif len(innerLoop) == 0:
            x += 1
        else:
            x += innerLoop[-1]
    index += 1
    
if x > overflow:
    print("OVERFLOW!!!")
else:
    print(x)
    