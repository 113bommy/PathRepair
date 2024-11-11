length = int(input())
number = input().strip()
lStart = length // 2

if length % 2 == 0:
    rStart = length // 2
else:
    rStart = (length // 2) + 1
    
lCut = 0 
for i in reversed(range(1, lStart + 1)):
    rSubstring = number[i:length]
    if not rSubstring.startswith('0'):
        lCut = i
        break
rCut = -1
for i in range(rStart, length):
    rSubstring = number[i:length]
    if not rSubstring.startswith('0'):
        rCut = i
        break

if lCut == 0:
    caseOne = int(number)
else:
    caseOneLeft = int(number[0:lCut])
    caseOneRight = int(number[lCut:length])
    caseOne = caseOneLeft + caseOneRight

# Case where there is no possible mid way cut
if rCut == -1:
    print(caseOne)
else :
    caseTwoLeft = int(number[0:rCut])
    caseTwoRight = int(number[rCut:length])
    caseTwo = caseTwoLeft + caseTwoRight

    print(min(caseOne, caseTwo))

