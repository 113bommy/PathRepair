contents = []
total = 0
counter = 0

while True:
    try:
        contents.append(input().split())
    except:
        break

total = int(contents[0][1])   
faliure = 0
for i in range(int(contents[0][0])):
    sign = contents[i+1][0]
    number = int(contents[i+1][1])
    if sign == '+':
        total += number
    else:    
        if total - number >= 0 :
            total -= number
        else:
            faliure += 1
print(total,faliure)