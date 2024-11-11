n = int(input())
s = input()
vow = "aeiouy"
def getConsVowels(s):
    for x in range(len(s)-1):
        if (s[x] in vow and s[x+1] in vow):
            return x
    return -1
while (getConsVowels(s)!= -1):
    s = s[:getConsVowels(s)+1] + s[getConsVowels(s)+2:]
print(s)
