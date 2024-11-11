n = int(input())
seq = input()

new = ''

index = 0

while index < n:
    temp = ''
    if index < n-1:
        temp = seq[index:index+2]
    if temp == 'RU' or temp == 'UR': 
        new += 'D'
        index += 1
    else:
        new += seq[index]
    index += 1

print(len(new))
