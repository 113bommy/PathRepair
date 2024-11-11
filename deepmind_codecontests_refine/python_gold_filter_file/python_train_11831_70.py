def isVowel(c):
    return c == 'a' or c=='e' or c=='i' or c=='o' or c=='u'
def isDigit(n):
    return n=='1' or n=='3' or n=='5' or n=='7' or n=='9'
c = 0
s = input()
for i in range(len(s)):
    if isVowel(s[i]) or isDigit(s[i]):
        c += 1
print(c)