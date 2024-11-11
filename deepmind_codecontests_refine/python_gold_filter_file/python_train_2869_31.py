n = int(input())
for i in range(n):
    word = str(input())
    if len(word) <= 10:
        print(word)
    else:
        print(word[0], len(word[1:-1]), word[-1], sep='')
