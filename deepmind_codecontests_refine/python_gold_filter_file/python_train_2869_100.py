n = int(input())
for i in range(n):
    word = input()
    savior = ''
    counter = 0
    for c in range(len(word)):
        if(len(word) < 11):
            savior += word
            break
        if((c == 0) or (c == len(word)-1)):
            savior += word[c]
        else:
            counter += 1
            if(c == len(word)-2):
                savior += str(counter)
    print(savior)
        
        
        
