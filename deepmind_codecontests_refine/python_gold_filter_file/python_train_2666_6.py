import  math
n = int(input())
s = input()
array = []
result = []
for i in s.split():
    array.append(i)
for i in range(len(array)):
    counter  = 0
    for j in range(len(array[i])):
        if ord(array[i][j]) < 91:
            counter += 1
    result.append(counter)
print(max(result))