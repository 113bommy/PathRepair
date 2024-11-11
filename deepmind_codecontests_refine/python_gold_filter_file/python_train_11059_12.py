for _ in range(int(input())):
    s = input()
    count, k = set(), 0
    for elem in s:
        if elem == 'L':
            k += 1
        else:
            count.add(k)
            k = 0
    count.add(k)
    print(str(max(count) + 1))
