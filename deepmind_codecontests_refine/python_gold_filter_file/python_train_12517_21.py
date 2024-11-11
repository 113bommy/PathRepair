testInput = input()
toCheck = ("H", "Q", "9")

testInput = set(testInput)

if testInput.isdisjoint(toCheck):
    print ("NO")   
else:
    print ("YES")