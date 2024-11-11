T = int(input())
for i in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    S = input()
    base = []
    for i in range(1,N+1):
        temp = A[-i]
        for x in base:
            temp = min(temp,temp^x)
        if temp != 0:
            if S[-i] == '1':
                print('1')
                break
            else:
                base.append(temp)
    else:
        print('0')