


def main():
    nb = int(input())
    tab = list(map(int,input().split()))
    dist = 0
    x = nb-1
    while x > 1:
        if tab[x] != tab[0]:
            dist = max(dist, x)
            break
        x-=1 
    for x in range(nb-1):
        if tab[nb-1] != tab[x]:
            dist = max(dist, nb-x-1)
            break
    print(dist)
main()