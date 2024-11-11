requests = int(input())

answers = []
for i in range(requests):
    numberOfPlates = int(input()) # кол-во досок
    fakeLengthOfPlates = input().split()
    lengthOfPlates = [] # их длины
    
    for i in fakeLengthOfPlates:
        lengthOfPlates.append(int(i))
    lengthOfPlates = sorted(lengthOfPlates, reverse = True)
    
    if numberOfPlates < 3:
        answers.append(0)
        continue
    else:
        a = lengthOfPlates[0]-1
        b = lengthOfPlates[1]-1
        answer = 0
        for i in range(2, numberOfPlates+1):
            if a == 0 or b == 0 or i == numberOfPlates:
                answers.append(answer)
                break
            else:
                a -= 1
                b -= 1
                answer += 1

for i in answers:
    print(i)
                
                
                
                
                
                
                
                
                
