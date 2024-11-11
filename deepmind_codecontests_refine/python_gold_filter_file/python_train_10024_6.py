def main():
    n = int(input())
    l = [int(x) for x in input().split()]
    print(calc(l))

def calc(l):
    ma = max(l)
    mi = min(l)
    r = [x for x in l]
    r.reverse()
    lma = l.index(ma)
    lmi = r.index(mi)
    total = lma+lmi
    if total>=len(l):
        total -=1
    return total
    
if __name__ == '__main__':
    main()