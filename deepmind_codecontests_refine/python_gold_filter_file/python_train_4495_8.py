C = ['a','e','i','o','u','y']
S = [x for x in list(input().lower()) if not x in C]
if len(S) > 0:
    word = '.'+'.'.join(S)
    print(word)

