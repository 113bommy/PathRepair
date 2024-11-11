num = int(input())
Strings = list()
for i in range(num):
    str = input()
    Strings.append(str)
for i in Strings:
    j = 0
    str = [j for j in i]
    str.sort()
    flag = True
    for j in range(len(str)-1):
        if ord(str[j]) != ord(str[j+1])-1:
            flag = False
    if flag == True:
            print('Yes')
    else:
        print('No')
            
        
    
