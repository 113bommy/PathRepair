# _
#####################################################################################################################

from math import sqrt, ceil


def min_nPeople(nTypes, nSwordsForEachType):
    nSwordsForEachType.sort()
    highestValue = nSwordsForEachType[-1]
    difference, iToConsider = 0, nTypes
    for i in range(nTypes-2, -1, -1):
        difference = highestValue - nSwordsForEachType[i]
        if difference:
            iToConsider = i
            break

    if not iToConsider:
        print(1, difference)
        return

    finalValue = nSwordsForEachType[iToConsider-1]
    for factor in factorsOf(difference):
        for value in nSwordsForEachType[:iToConsider]:
            if (highestValue-value)%factor:
                break
            elif value == finalValue:
                factor = round(factor)
                print((highestValue*nTypes - sum(nSwordsForEachType))//factor, factor)
                return


def factorsOf(n):
    if n == 1:
        yield 1
        return

    factorsStorage, squareRoot_n = [], sqrt(n)
    limit = ceil(squareRoot_n)
    for value in range(1, limit):
        if not n%value:
            yield n/value
            factorsStorage.append(value)

    if squareRoot_n == limit:
        yield limit

    factorsStorage.reverse()
    for factor in factorsStorage:
        yield factor


min_nPeople(int(input()), list(map(int, input().split())))
