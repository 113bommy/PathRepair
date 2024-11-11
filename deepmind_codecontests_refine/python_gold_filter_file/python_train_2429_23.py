n = int(input())
a = input()
digits = list(map(int, list(a)))
firsthalf, secondhalf = sorted(digits[:n]), sorted(digits[-n:])
if firsthalf[0] > secondhalf[0]:
    for x in range(n):
        if firsthalf[x] <= secondhalf[x]:
            print("NO")
            break
    else:
        print("YES")
else:
    for x in range(n):
        if firsthalf[x] >= secondhalf[x]:
            print("NO")
            break
    else:
        print("YES")