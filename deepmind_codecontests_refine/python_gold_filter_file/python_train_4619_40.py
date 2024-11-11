nproblem = int(input())
question = {}
output = 0
for i in range(0,nproblem):
    temp = input()
    question[i] = temp.split()
for x in question:
    sum = 0
    for y in range(0,3):
        sum = sum + int(question[x][y])
    if(sum>(3/2)):
        output = output + 1
print(output)
