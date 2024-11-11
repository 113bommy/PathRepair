T = int(input())
for _ in range(T):
    S = "R" + input()
    L = S.split("R")
    #print(L)
    seq = max([len(v) for v in L])
    print(seq+1)
