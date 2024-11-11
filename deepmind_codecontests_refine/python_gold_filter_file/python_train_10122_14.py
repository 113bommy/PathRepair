for _ in range(int(input())):
    a, b = map(int, input().split())
    if a == b:
        print('0')
    elif (a > b and a & 1 == b & 1) or (a < b and a & 1 != b & 1):
        print('1')
    else:
        print('2') 
