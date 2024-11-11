key= ['q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/']
direct=str(input())
mole= str(input())
for i in mole:
    for j in range(len(key)):
        if i==key[j] and direct=='R':
            print(key[j-1], end='')
        if i==key[j] and direct == 'L':
            print(key[j+1], end='')