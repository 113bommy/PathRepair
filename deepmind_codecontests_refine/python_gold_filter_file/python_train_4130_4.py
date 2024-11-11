from sys import stdin, stdout

len_array = int(stdin.readline())
array = list(map(int, stdin.readline().split(' ')))

rem_array = list()

container = set(array)

i = len_array - 1
while i >= 0:
    if array[i] in container:
        container.remove(array[i])
        rem_array.append(array[i])
    i -= 1 

j = len(rem_array)-1
print(j+1)
while j >= 0:
    print(rem_array[j], end=' ')
    j -= 1

    