t = int(input())

for queries in range(t):
    n = int(input())
    m = n
    r = 2
    array = []
    while r <= 25000:
        if n % r == 0:
            array.append(r)
            n //= r
        r += 1
        if len(array) == 2:
            break
    if len(array) == 2 and n > array[1]:
        print("YES")
        print(array[0],array[1],m//array[0]//array[1])

    else:
        print("NO")
