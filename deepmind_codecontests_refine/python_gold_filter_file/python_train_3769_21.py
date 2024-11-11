q = input()
for i in range(int(q)):
    sum1= 0
    n = int(input())
    inp = input().split()
    for item in inp:
        sum1 = sum1 + int(item)
    if sum1%n == 0:
        print(sum1//n)
    else:
        print((sum1+n-1)//n)