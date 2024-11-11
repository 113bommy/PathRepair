n = int(input())
answer = []
num=[]
for i in range(n):
    m=int(input())
    a = input()
    if len(a) == 2:
        c = int(a[0])
        f = int(a[1])
        if c<f:
            answer.append('YES')
            num.append(a)
        else:
            answer.append('NO')
            num.append(a)
    if len(a)>=3:
        answer.append('YES')
        num.append(a)
for i in range(n):
    print(answer[i])
    if answer[i] == 'YES':
        print('2')
        print(num[i][0],num[i][1:])
