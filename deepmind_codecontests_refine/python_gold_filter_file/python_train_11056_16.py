for i in range(int(input())):
    a, b = (int(x) for x in input().split())
    s = 'Yes'
    if a <= 3 and a != b:
        s = 'No'
    if a == 2 and b == 3 or a > b:
        s = 'Yes'
    print(s)