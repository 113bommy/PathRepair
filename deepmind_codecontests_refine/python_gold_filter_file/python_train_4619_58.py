n = int(input())
countz = 0
for i in range(0, n):
    x = input()
    if x.count('1') >= 2:
        countz += 1
print(countz)