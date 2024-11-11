n = int(input())
ai = list(map(int,input().split()))
# find maxNegNumber multiple them if NegNumbers  are 2n + 1 exclude this MaxNegNumber
#multiple all positive
#multiple all zeros multiple it with MaxNegNumber if needed than exclude it with second option
maxNegNumber  = -10000000000
maxInd = 0
numberOfNeg = 0
for i in range(n):
    if ai[i] < 0:
        numberOfNeg += 1
        if maxNegNumber < ai[i]:
            maxInd = i
            maxNegNumber = ai[i]
prev = -1
num0 = 0
for i in range(n):
    if ai[i] > 0:
        if prev == -1:
            prev = i
            continue
        print(1, prev + 1, i + 1)
        prev = i
for i in range(n):
    if ai[i] < 0 and (numberOfNeg % 2 == 0 or maxInd != i):
        if prev == -1:
            prev = i
            continue
        print(1, prev + 1, i + 1)
        prev = i
        
prev = -1
for i in range(n):
    if ai[i] == 0:
        num0 += 1
        if prev == -1:
            prev = i
            continue
        print(1, prev + 1, i + 1)
        prev = i

if prev != -1 and numberOfNeg % 2 == 1:
    print(1, prev + 1, maxInd + 1)
    if num0 != n - 1:
        print(2, maxInd + 1)
elif prev != -1:
    if num0 != n:
        print(2, prev + 1)
elif numberOfNeg % 2 == 1:
    print(2, maxInd + 1)
        
