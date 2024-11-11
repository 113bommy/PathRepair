for _ in range(int(input())):
    data = list(map(int, input().split()))
    data.sort()
    if data[2]-1<=data[0]+data[1]:
        print('Yes')
    else:
        print('No')

