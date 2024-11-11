x,y,z = map(int, input().split())
if x%z==0 or y%z==0:
    print(x//z + y//z,end=' ')
    print('0')
else:
    if x%z>=y%z and x%z + y%z >= z:
        print(x//z + y//z + 1,end=' ')
        print(z - x%z)
    elif x%z>=y%z and x%z + y%z < z:
        print(x//z + y//z,end=' ')
        print('0')
    elif x%z<=y%z and x%z + y%z >= z:
        print(x//z + y//z + 1,end=' ')
        print(z - y%z)
    else:
        print(x//z + y//z,end=' ')
        print('0')