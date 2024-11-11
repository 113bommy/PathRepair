def solve():
    #if len of string even, all 2s
    #if len odd 3 and 2s
    n = int(input())
    str = input()
    for i in range(0,len(str),2):
        if len(str)-i <= 3:
            print(str[i:],end='')
            break
        else:
            print(str[i:i+2],end='-')

solve()