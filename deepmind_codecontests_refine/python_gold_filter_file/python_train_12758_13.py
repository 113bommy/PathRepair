n = input()

i = 0
while(i < len(n)):
    if(n[i] == 'a'):
        i += 1
    else:
        break
if(i == len(n)):
    print(n[:i-1]+'z')
else:
    j = i
    while(j < len(n)):
        if(n[j] != 'a'):
            j += 1
        else:
            break

    s = n[:i]
    for z in range(i, j):
        s = s + chr(ord(n[z])-1)
    s = s + n[j:]
    print(s)
