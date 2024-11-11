
def main():
    n = int(input())
    aa = [int(a) for a in input().split()]
    counts = [0] * 30
    candidate = [None] * 30
    for a in aa:
        i = 0
        b = a
        while b > 0:
            if b%2 == 1:
                counts[i] += 1
                if counts[i] == 1:
                    candidate[i] = a
                else:
                    candidate[i] = None
            b = b//2
            i+=1
    for c in candidate[::-1]:
        if c:
            aa.remove(c)
            print(c, ' '.join(map(str, aa)))
            break
    else:
        print(' '.join(map(str, aa)))



if __name__ == "__main__":
    main()