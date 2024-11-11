n = int(input())

Line = input()
Lines = Line.split(' ')

for i in range(len(Lines)):
   Lines[i] = int(Lines[i])

sum = 0

Arg = input()

Args = Arg.split(' ')
for i in range(len(Args)):
    Args[i] = int(Args[i])

for i in range(Args[0], Args[1]):
    sum += Lines[i - 1]

print(sum)