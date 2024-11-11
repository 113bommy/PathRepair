GI = lambda: int(input()); GIS = lambda: map(int, input().split()); LGIS = lambda: list(GIS())

def main():
    n = GI()
    l = LGIS()
    
    i = 0
    x = l[-1]
    while l[i] == x:
        i += 1
    dl = n - 1 - i

    i = n-1
    x = l[0]
    while l[i] == x:
        i -= 1
    dr = i

    print(max(dl, dr))

main()
