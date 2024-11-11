total = int(input())
num_l = list(map(int,input().split()))
if total == 1:
    print('1 1')
    print(-num_l[0])
    print('1 1')
    print('0')
    print('1 1')
    print('0')
elif total == 2:
    print('1 1')
    print(-num_l[0])
    print('2 2')
    print(-num_l[1])
    print('1 1')
    print('0')
else:
    print('1 '+str(total-1))
    mul1 = total - 1
    mul1_l = []
    for count in range(total-1):
        mul1_l.append(mul1*num_l[count])
    print(*mul1_l)
    
    print('1 '+str(total))
    mul2 = total
    mul2_l = []
    for count in range(total-1):
        mul2_l.append(-mul2*num_l[count])
    mul2_l += [0]
    print(*mul2_l)
    
    print(str(total)+' '+str(total))
    print(-num_l[total-1])