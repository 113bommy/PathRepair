# Get the data from the user
myInput = iter(input().split())

numOfGroups = int(next(myInput))
numOfOneSeater = int(next(myInput))
numOfTwoSeaters = int(next(myInput))
numOfHalfTable = 0

# Main operation
denied = 0
myInput = iter(input().split())

for i in range(numOfGroups):
    current = int(next(myInput))

    if current == 1:
        if numOfOneSeater >= 1:
            numOfOneSeater -= 1
        elif numOfTwoSeaters >= 1:
            numOfHalfTable += 1
            numOfTwoSeaters -= 1
        elif numOfHalfTable >= 1:
            numOfHalfTable -= 1
        else:
            denied += 1
    else:
        if numOfTwoSeaters >= 1:
            numOfTwoSeaters -= 1
        else:
            denied += 2

# Print the result
print(denied)
