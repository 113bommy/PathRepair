for _ in range(int(input())):
    n,a,b = map(int,input().split())
    s = 'abcdefghijklmnopqrstuvwxyz'
    temp = s[:b]
    q = a//b
    r = a%b
    temp *= q
    temp += s[:r]
    q = n//a
    r = n%a
    temp *=q
    temp += temp[:r]
    print(temp)