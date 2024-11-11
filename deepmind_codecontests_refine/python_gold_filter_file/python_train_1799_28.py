tt = int(input())
for _ in range(tt):
    noOfSquares = int(input())
    totalStairs = 0
    length = 1
    p = 1

    while noOfSquares > 0:
        totalSquaresRequired = (length*(length+1)) // 2
        if (noOfSquares >= totalSquaresRequired):
            totalStairs += 1
            noOfSquares -= totalSquaresRequired
            p = p * 2
            length += p
        else:
            break
    print(totalStairs)


