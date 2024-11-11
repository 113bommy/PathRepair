t = int(input())
numbers = list(map(int, input().strip().split()))

for number in numbers:
    x = number // 14
    tmp = number - x*14
    
    if(x==0):
        print('NO')
    else:
        if(tmp in [1,2,3,4,5,6]):
            print('YES')
        else:
            print('NO')