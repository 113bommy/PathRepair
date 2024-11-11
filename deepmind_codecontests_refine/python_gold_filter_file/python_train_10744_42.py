def test(r, g, b):
    if r + g >= b-1 and r + b >= g-1 and g + b >= r-1:
        print('Yes')
    else:
        print('No')

        
for i in range(int(input())):
    r, g, b = map(int, input().split())
    test(r, g, b)