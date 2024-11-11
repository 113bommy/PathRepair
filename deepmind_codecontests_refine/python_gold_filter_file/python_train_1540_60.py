N,_ = map(int, input().split())
z = N - eval(input().replace(*' +'))
print(z if  0 <= z else -1 )