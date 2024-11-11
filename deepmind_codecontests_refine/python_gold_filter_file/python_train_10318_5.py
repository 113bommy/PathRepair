import collections
def main():
    a = int(input())
    b = list(map(int,input().split()))
    Temp = collections.Counter(b)
    num1, num2, num3 = 0, 0, 0
    for c in Temp.values():
        if c == 1: num1 += 1
        elif c == 2: num2 += 1
        else: num3 += 1
    if num1 % 2 == 1 and num3 ==0:
        print('NO')
        exit()
    print('YES')
    A, B, C = 0, 0, 0
    if num1 % 2 == 0:
        C += 1
    Str = []
    for d in b:
        if Temp[d] ==1:
            if A == B:
                Str.append('A')
                A += 1
            else:
                Str.append('B')
                B += 1
        elif Temp[d] >=3 and C ==0:
            Str.append('B')
            C += 1
        else:
            Str.append('A')
    print(''.join(Str))
if __name__ =='__main__':
    main()

