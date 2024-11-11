for i in range(int(input())):
    n, s = int(input()), input()
    
    for i in range(n//2):
        if abs(ord(s[i])-ord(s[-i-1])) not in [0,2]:
            print('NO')
            break
    else:
        print('YES')