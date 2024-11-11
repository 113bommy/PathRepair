for i in range(int(input())):
    wordl = [ord(l) for l in list(input())]
    q = len(wordl)
    words = set(wordl)
    a = min(wordl)
    #print(set(range(a - len(wordl) + 1, a + 1)))
    #print(wordl)
    if set(range(a, a + q)) == words:
        print('Yes')
    else:
        print('No')