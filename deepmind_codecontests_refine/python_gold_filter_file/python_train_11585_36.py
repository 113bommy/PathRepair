t = int(input())
for i in range(t):
    a, b = input().split()
    a = int(a)
    b = int(b)
    result = 0
    if a == b : result = 0
    elif (a > b and (a-b) % 2 == 0) or (a < b and (b-a) % 2 == 1): result = 1
    else: result = 2
    print(result)