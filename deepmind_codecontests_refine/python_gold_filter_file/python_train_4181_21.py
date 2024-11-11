totalStrings = int(input())
for i in range(totalStrings):
    letters = [0] * 28
    word = str(input())
    start = 0
    end = 0
    for letter in word:
        letters[ord(letter)-96] +=1
    for j in range(len(letters)):
        if letters[j] == 1:
            start = j
            break
    for j in range(start,len(letters)):
        if letters[j] == 0:
            end = j
            break
##    print(end-start)
    if end-start == len(word):
        print("Yes")
    else:
        print("No")

