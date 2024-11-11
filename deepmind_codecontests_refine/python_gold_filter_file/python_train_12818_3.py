import string
import math
def main():
    n,x,y = map(int,input().split())
    tab = list(map(int,input().split()))
    inc = 0
    tab.sort()
    while len(tab) > 0 and x >= tab[0]:
        tab.pop(0)
        if len(tab) > 0:
            tab[0] += y
            tab.sort()
        inc += 1
    n = len(tab)
    
    if y >= x:
        print(inc)
        return
    x -= y
    
    nb_tours = inc
    while nb_tours < 10**100 and len(tab) > 0:
        nb_tours += math.ceil(tab[0]/x)
        inc += 1
        tab.pop(0)
    print(inc)
    
    
main()