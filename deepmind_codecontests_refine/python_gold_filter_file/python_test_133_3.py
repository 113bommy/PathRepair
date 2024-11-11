t = int(input())
for i in range(t):
    n = int(input())
    bigrams = input().split()
    word = bigrams[0]
    for j in bigrams[1:]:
        word += j[1] if word[-1] == j[0] else j
    print(word.ljust(n, "a"))
