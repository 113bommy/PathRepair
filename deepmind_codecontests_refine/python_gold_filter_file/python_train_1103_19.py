k = int(input())
data = [0 for i in range(10)]
box = 0
for i in [int(i) for i in input()]:
    box += i
    data[i] += 1
ret = 0
for i in range(9):
    if box < k:
        for j in range(data[i]):
            if box < k:
                box += 9 - i
                ret += 1
            else:
                break
    else:
        break
print(ret)
    
    