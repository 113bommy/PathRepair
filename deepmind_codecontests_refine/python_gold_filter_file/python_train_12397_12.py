while True:
    a, b = sorted([int(i) for i in input().split()])
    if not(a or b):
        break
    print(a,b)