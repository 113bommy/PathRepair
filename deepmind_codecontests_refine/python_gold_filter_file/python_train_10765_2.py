n = input()
for i in range(len(n)-1,-1,-1):
    dig = int(n[i])
    if dig // 5:
        print("-O|",end="")
    else:
        print("O-|",end="")
    print('O' * (dig % 5) + '-' + 'O' * (4 - dig % 5))
