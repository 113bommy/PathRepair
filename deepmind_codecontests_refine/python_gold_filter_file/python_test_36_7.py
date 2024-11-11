t = int(input())

for _ in range(t):
    n = int(input())
    row = [int(i) for i in input().split()]
    summ = sum(row)
    result = list(range(1, len(row)+1))
    flag = True
    for j in range(2, round(summ**0.5)+2):
        if summ % j == 0:
            flag = False
            break

    if flag:
        for i in range(len(row)):
            if row[i] % 2 == 1:
                result.pop(i)
                break

    print(len(result))
    abc = ' '.join(str(i) for i in result)
    print(abc)



