n = int(input())
array = [int(k) for k in input().split()]
actual = array.copy()
for i in range(len(array)//2):
    if (i + 1) % 2 == 0:
        continue
    else:
        temp = actual[i]
        actual[i] = actual[n-i-1]
        actual[n-i-1] = temp
print(*actual)