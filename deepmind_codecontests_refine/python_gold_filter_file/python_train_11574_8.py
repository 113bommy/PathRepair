def countVowels(s):
    vowels = ["a","e","i","o","u"]
    count = 0
    for i in range(len(s)):
        if s[i] in vowels:
            count+=1
            lastVowel = s[i]
    return (count,lastVowel)

n = int(input())
d = {}
second = []
for i in range(n):
    word = input()
    x = countVowels(word)
    if x[0] in d:
        v = d[x[0]]
        if x[1] in v:
            arr = v[x[1]]
            if len(arr) == 1:
                item = arr.pop()
                second.append((item,word))
            else:
                arr.append(word)
        else:
            v[x[1]] = [word]
        
    else:
        d[x[0]] = {x[1]:[word]}
first = []
for n in d:
    v = d[n]
    prev = None
    for e in v:
        arr = v[e]
        if len(arr) == 1:
            if prev == None:
                prev = arr[0]
            else:
                first.append((prev,arr[0]))
                prev = None
if len(first) >= len(second):
    print(len(second))
    for i in range(len(second)):
        print(first[i][0]+" "+second[i][0])
        print(first[i][1]+" "+second[i][1])
else:
    print(len(first)+int((len(second)-len(first))/2))
    for i in range(len(first)):
        print(first[i][0]+" "+second[i][0])
        print(first[i][1]+" "+second[i][1])
    i=len(first)
    while i<len(second):
        if i+1<len(second):
            print(second[i][0]+" "+second[i+1][0])
            print(second[i][1]+" "+second[i+1][1])
            i+=2
        else:break
