def i_ints():
    return list(map(int, input().split()))

#############

n, a, b = i_ints()
def calc():
    if min(a, b) != 1:
        print("NO")
        return
    if a == b == 1 and n in (2, 3):
        print("NO")
        return
    
    print("YES")
    ONE, ZERO = "10" if a > 1 else "01"

    edges = n - max(a, b)
    line = "0" + (ZERO, ONE)[edges>0]*(n>1) + ZERO * (n-2)
    print(line)
    
    for y in range(1, n):
        line = ZERO * (y-1) + (ZERO, ONE)[y<=edges] + "0"
        if y < n-1:
            line += (ZERO, ONE)[y < edges] + ZERO * (n-y-2)
        print(line)
                
                

calc()

