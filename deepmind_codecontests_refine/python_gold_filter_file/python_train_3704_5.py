import math

input_string = input()

map = []
first_index = []

for i in range(0,26):
    map.append(0)
    first_index.append(math.inf)

for i in range(0, len(input_string)):

    if map[ord(input_string[i]) - 97] == 0:
        first_index[ord(input_string[i]) - 97] = i


    map[ord(input_string[i]) - 97]+=1

fault = False

for i in range(1, len(map)):
    if map[i - 1] == 0 and map[i] > 0:
        fault = True
        break


for i in range(0, len(first_index) - 1):
    if first_index[i] > first_index[i + 1]:
        fault = True
        break

if fault == True:
    print("NO")
else:
    print("YES")
    
