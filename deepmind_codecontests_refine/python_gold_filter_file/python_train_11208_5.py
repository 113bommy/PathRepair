n = int(input())
String = input()

rejectedSub = "xxx"
removeCount = 0
for i in range(n):
    if rejectedSub in String[i:i+3]:
        removeCount += 1
print(removeCount)
