n = int(input())
array = list(map(int, input().split()))


if n == 1 or (n == 2 and array[0] == array[1]):
    print(-1)
else:
    solNumber = 1
    solArray = [1]
    s = sum(array[i] for i in range(1, n))
    if array[0] == s:
        solNumber += 1
        solArray.append(2)

    print(solNumber)
    for item in solArray:
        print(item, end = " ")
