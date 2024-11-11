from sys import stdin, gettrace
from collections import Counter

# if not gettrace():
#     def input():
#         return next(stdin)[:-1]
#

def input():
   return stdin.buffer.readline()

def main():
    n,k = map(int, input().split())
    aa = [int(a) for a in input().split()]
    aac = sorted(Counter(aa).most_common())
    lac = len(aac)
    prefcount = 0
    prefcost = 0
    prefcosts = [0]*lac
    prefcounts = [0]*lac
    pa = 0
    for i, (a,c) in enumerate(aac):
        prefcost += prefcount*(a - pa)
        prefcount += c
        prefcosts[i] = prefcost
        prefcounts[i] = prefcount
        pa = a
    sufcount = 0
    sufcost = 0
    sufcosts = [0]*lac
    sufcounts = [0]*lac
    pa = 0
    for i, (a,c) in enumerate(aac[::-1], 1):
        if c >= k:
            print(0)
            return
        sufcost += sufcount*(pa - a)
        sufcount += c
        sufcosts[lac - i] = sufcost
        sufcounts[lac - i] = sufcount
        pa = a
    best = int(10E18)
    for i in range(lac):
        if prefcounts[i] >= k:
            lc = prefcosts[i-1] + (aac[i][0] - aac[i-1][0]-1)*prefcounts[i-1] + k-aac[i][1]
        else:
            lc = prefcosts[i] + sufcosts[i+1] + sufcounts[i+1] * (aac[i+1][0] - aac[i][0] - 1) + k - prefcounts[i]
        if sufcounts[i] >= k:
            rc = sufcosts[i+1] + (aac[i+1][0] - aac[i][0]-1)*sufcounts[i+1] + k-aac[i][1]
        else:
            rc = sufcosts[i] + prefcosts[i-1] + prefcounts[i-1] * (aac[i][0] - aac[i-1][0] - 1) + k - sufcounts[i]
        best = min(lc, rc, best)
    print(best)






if __name__ == "__main__":
    main()