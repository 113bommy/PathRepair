from sys import stdin

def main():
    n = int(input())
    aa = input().split()
    aad = [[int(ad) for ad in a] for a in aa]
    sums = []
    dcount = []
    for a in aad:
        l = len(a)
        for i in range(l):
            if i >= len(sums):
                sums.append(a[-i-1])
                dcount.append(1)
            else:
                sums[i] += a[-i-1]
                dcount[i] += 1
    digits = len(sums)
    sums += [0] * digits
    lencount = [dcount[n] - dcount[n+1] for n in range(digits-1)] + [dcount[-1]]
    sums2 = [0]*(digits *2)
    for i in range(digits):
        sums2[i*2] = sums[i]*dcount[i]
        sums2[i*2+1] = sums[i]*dcount[i]
        for j in range(i):
            sums2[i*2] += sums[i*2-j-1]*lencount[j]*2
            sums2[i*2+1] += sums[i*2-j]*lencount[j]*2
    res = 0
    for i in range(len(sums2)-1, -1, -1):
        res = (sums2[i] + res*10 ) % 998244353

    print(res)

if __name__ == "__main__":
    main()
