s = input()
language = "HQ9"
isLanguage = False
for c in s:
    if c in language :
        print("YES")
        isLanguage = True
        break
if not isLanguage :
    print("NO")