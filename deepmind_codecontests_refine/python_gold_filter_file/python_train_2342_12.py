import sys

def findMinimumMaxBetweenCities(cities, qtyCities):
  for i in range(qtyCities):
    currentCity = cities[i]
    minLeft = sys.maxsize
    minRight = minLeft

    if (i - 1 >= 0):
      minLeft = currentCity - cities[i - 1]
    
    if (i + 1 < qtyCities):
      minRight = cities[i + 1] - currentCity
    
    minDistance = min(minLeft, minRight)
    maxDistance = max(cities[qtyCities - 1] - currentCity, currentCity - cities[0])

    print("{0} {1}".format(minDistance, maxDistance))

numOfCities = int(input())
citiesPosition = list(map(lambda x: int(x), input().split()))

findMinimumMaxBetweenCities(citiesPosition, numOfCities)
