s = input()
alph = "abcdefghijklmnopqrstuvwxyz"
print("Mike")
mn = alph.find(s[0])
for i in range(1, len(s)):
    if (alph.find(s[i]) > mn):
        print('Ann')
    else:
        mn = alph.find(s[i])
        print('Mike')