n = int(input())
a = input()
b = input()
result = 0
index = 0
while index < n - 1:
    if (a[index] != b[index]):
        if (a[index] != a[index+1]) and (a[index+1] != b[index+1]):
                result += 1
                index += 2
        else:
            result += 1
            index += 1
    else:
        index += 1
if index == n - 1:
    if a[index] != b[index]:
        result += 1
print(result)

