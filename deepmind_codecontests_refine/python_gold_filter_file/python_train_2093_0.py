n = int(input())
s = input()
arr = list()
arr.append(int(s[0]))
summ = arr[0]
bigflg = False
for i in range(1,len(s)):
    arr.append(int(s[i]))
    summ+=arr[i]
for i in range(2,len(s)+1):
    if summ % i == 0:
        amount = summ / i
        sm = 0
        flg = True
        for j in range(len(arr)):
            sm += arr[j]
            if (sm > amount):
                flg = False
                break
            if (sm == amount):
                sm = 0
        if sm==0 and flg:
            bigflg = True
            print('YES')
            break
if not bigflg:
    print('NO')
