s = input()
resultWord = 'hello'
k = 0
isOk = False
for i in range(len(s)):
    if s[i] == resultWord[k]:
        k += 1
        if k == len(resultWord):
            isOk = True
            break
if isOk:
    print('YES')
else:
    print('NO')