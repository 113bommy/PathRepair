n = input()
print(int(input().replace('B', '1').replace('R', '0')[::-1] , 2))