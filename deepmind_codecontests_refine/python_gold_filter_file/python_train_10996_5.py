if __name__ == "__main__":

    n = int(input())
    maxNine = len(str(n*2))-1

    base = int(10**maxNine)
    count = n // base
    remainder = n%base
    res = 0

    if maxNine == 0:
        res = n*(n-1)//2
    elif remainder*2 < base:
        res = (count+1)*remainder*count + count*count*(base//2 - remainder)
    else:
        bonusCount = remainder - base//2 + 1
        res = (count+1)*(count+1)*bonusCount + (count+1)*count*(base//2 - bonusCount)
        res -= (n+1)//base

    print(res)