n = input()
bool = True
for i in range(len(n)):
    if i == 0:
        if n[i] != '1':
            print('NO')
            bool = False
            break
    if n[i] == '1' or n[i] == '4':
        if n[i] == '1' and i <= len(n)-4 and '1' not in n[i+1:i+4]:
            print('NO')
            bool = False
            break
    else:
        print('NO')
        bool = False
        break
if bool:
    print('YES')
