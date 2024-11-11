x, n = list(map(int, input().split()))
p = list(map(int, input().split()))
pN = [i for i in range(102) if i not in p]
pNm = [abs(i - x) for i in pN]
pmin = min(pNm)
print(pN[pNm.index(pmin)])