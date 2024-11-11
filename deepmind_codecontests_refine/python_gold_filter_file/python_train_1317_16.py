x = int(input())
y = input()

def operations(x):
    if x == 0:
        return 0
    if x % 2 == 0:
        part = int(x/2)
        if y[0:part] == y[part:2*part]:
            return part + 1
        else:
            return 1 + operations(x-1)
    else:
        return 1 + operations(x-1)

print(operations(x))