n = int(input())
cubesleft = n-1
floors = 1
 
if n <= 3:
    print(1)
else:
    for i in range(n):
        floors +=1
        sum = (((floors) * (floors+1)) / 2)
        cubesleft -= sum
        if sum > cubesleft+sum:
            floors -=1
            print(floors)
            break