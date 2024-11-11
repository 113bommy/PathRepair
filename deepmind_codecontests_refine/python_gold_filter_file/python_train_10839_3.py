for i in range(int(input())):
    a,b,k = map(int,input().split())
    print(int(a*(k//2)+a*(k%2)-b*(k//2)))