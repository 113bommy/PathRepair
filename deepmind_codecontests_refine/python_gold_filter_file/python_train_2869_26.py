n = int(input())

lst = []
for i in range(n):
    word = input()
    if len(word) <= 10:
        lst.append(word)
    else:
        abb = word[0] + str(len(word) - 2) + word[-1]
        lst.append(abb)

for i in range(n):
    print(lst[i])