s = input()
k = int(input())

array = []
for i in range(0, k):
    for j in range(0, len(s)-i):
        array.append(s[j:j+i+1])

print(sorted(set(array))[k-1])