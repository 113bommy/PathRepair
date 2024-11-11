n, x, y = map(int, input().split())
a = [int(d) for d in input().split()]
    
if x > y:
    print(n)
else:
    vypilivaemye = 0
    for d in a:
        if d <= x:
            vypilivaemye += 1
    print((vypilivaemye + 1) // 2)