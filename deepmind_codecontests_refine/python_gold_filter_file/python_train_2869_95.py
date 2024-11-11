n = int(input())
words = []
for i in range(n):
    temp = input()
    words.append(temp)
for i in range(n):
    temp = words[i]
    size = len(temp)
    if size > 10:
        print(temp[0]+str(size - 2)+temp[-1])
    else:
        print(temp)